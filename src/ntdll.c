#include "ntdll.h"
#include "system.h"
#include "types.h"
#include "apihash.h"

BOOL NTDLL_Ctor(NTDLL *ntdll)
{
    if (ntdll == NULL)
        return FALSE;
    
    PVOID module;
    module = GetModuleHandleFromPEB(HASH_MOD_NTDLL);
    if (module == NULL)
        return FALSE;

    ntdll->LdrLoadDll = (NTSTATUS (WINAPI *)(WCHAR *, UINT32, PUNICODE_STRING, PVOID *)) ResolveExportByHash(module, HASH_LDRLOADDLL);
    ntdll->RtlGetVersion = (NTSTATUS (WINAPI *)(PVOID)) ResolveExportByHash(module, HASH_RTLGETVERSION);

    return (ntdll->LdrLoadDll != NULL && ntdll->RtlGetVersion != NULL);
}
