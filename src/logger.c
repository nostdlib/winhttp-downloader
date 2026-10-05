#include "logger.h"
#include "types.h"
#include "apihash.h"

#ifdef LOGGING_ENABLED

#include "system.h"
#include "wintypes.h"

#define STD_OUTPUT_HANDLE  ((DWORD)-11)

void log_write(const char* buffer, unsigned long len)
{
    if (buffer == NULL || len == 0)
        return;

    HANDLE (WINAPI *pGetStdHandle)(DWORD) = (HANDLE (WINAPI *)(DWORD))ResolveFromModuleByHash(HASH_MOD_KERNEL32, HASH_GETSTDHANDLE);
    BOOL (WINAPI *pWriteFile)(HANDLE, const void *, DWORD, DWORD *, PVOID) = (BOOL(WINAPI *)(HANDLE, const void *, DWORD, DWORD *, PVOID))ResolveFromModuleByHash(HASH_MOD_KERNEL32, HASH_WRITEFILE);

    if (pGetStdHandle == NULL || pWriteFile == NULL)
        return;

    HANDLE stdout_handle = pGetStdHandle(STD_OUTPUT_HANDLE);
    if (!stdout_handle || stdout_handle == (HANDLE)-1)
        return;

    DWORD written = 0;
    pWriteFile(stdout_handle, (void*)buffer, (DWORD)len, &written, NULL);
}

#endif /* LOGGING_ENABLED */
