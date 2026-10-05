#include "advapi.h"
#include "system.h"
#include "apihash.h"
#include "djb2.h"

BOOL ADVAPI_Ctor(PADVAPI advapi)
{
    if (advapi == NULL)
        return FALSE;
    PVOID module = GetModuleHandleFromPEB(HashAscii("advapi32.dll"));

    advapi->RegOpenKeyExA = (LSTATUS (WINAPI *)(HKEY, const PCHAR, DWORD, REGSAM, HKEY*))
        ResolveExportByHash(module, HashAscii("RegOpenKeyExA"));
    advapi->RegQueryValueExA = (LSTATUS (WINAPI *)(HKEY, const PCHAR, DWORD*, DWORD*, unsigned char*, DWORD*))
        ResolveExportByHash(module, HashAscii("RegQueryValueExA"));
    advapi->RegCloseKey = (LSTATUS (WINAPI *)(HKEY))
        ResolveExportByHash(module, HashAscii("RegCloseKey"));
    advapi->GetUserNameA = (BOOL (WINAPI *)(PCHAR, DWORD *))
        ResolveExportByHash(module, HashAscii("GetUserNameA"));

    return (advapi->RegOpenKeyExA != NULL && advapi->RegQueryValueExA != NULL && advapi->RegCloseKey != NULL && advapi->GetUserNameA != NULL);
}
