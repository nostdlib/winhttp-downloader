#include "logger.h"
#include "types.h"
#include "djb2.h"

#ifdef LOGGING_ENABLED

#include "system.h"
#include "wintypes.h"

#define STD_OUTPUT_HANDLE  ((DWORD)-11)

void log_write(const char* buffer, unsigned long len)
{
    if (buffer == NULL || len == 0)
        return;

    HANDLE (WINAPI *pGetStdHandle)(DWORD) = (HANDLE (WINAPI *)(DWORD))ResolveFromModuleByHash(HashAscii("kernel32.dll"), HashAscii("GetStdHandle"));
    BOOL (WINAPI *pWriteFile)(HANDLE, const void *, DWORD, DWORD *, PVOID) = (BOOL(WINAPI *)(HANDLE, const void *, DWORD, DWORD *, PVOID))ResolveFromModuleByHash(HashAscii("kernel32.dll"), HashAscii("WriteFile"));

    if (pGetStdHandle == NULL || pWriteFile == NULL)
        return;

    HANDLE stdout_handle = pGetStdHandle(STD_OUTPUT_HANDLE);
    if (!stdout_handle || stdout_handle == (HANDLE)-1)
        return;

    DWORD written = 0;
    pWriteFile(stdout_handle, (void*)buffer, (DWORD)len, &written, NULL);
}

#endif /* LOGGING_ENABLED */
