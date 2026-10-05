#include "advapi.h"
#include "system.h"
#include "apihash.h"

BOOL ADVAPI_Ctor(PADVAPI advapi)
{
    if (advapi == NULL)
        return FALSE;
    PVOID module = GetModuleHandleFromPEB(HASH_MOD_ADVAPI32);

    advapi->RegOpenKeyExA = (LSTATUS (WINAPI *)(HKEY, const PCHAR, DWORD, REGSAM, HKEY*))
        ResolveExportByHash(module, HASH_REGOPENKEYEXA);
    advapi->RegQueryValueExA = (LSTATUS (WINAPI *)(HKEY, const PCHAR, DWORD*, DWORD*, unsigned char*, DWORD*))
        ResolveExportByHash(module, HASH_REGQUERYVALUEEXA);
    advapi->RegCloseKey = (LSTATUS (WINAPI *)(HKEY))
        ResolveExportByHash(module, HASH_REGCLOSEKEY);
    advapi->GetUserNameA = (BOOL (WINAPI *)(PCHAR, DWORD *))
        ResolveExportByHash(module, HASH_GETUSERNAMEA);

    return (advapi->RegOpenKeyExA != NULL && advapi->RegQueryValueExA != NULL && advapi->RegCloseKey != NULL && advapi->GetUserNameA != NULL);
}
