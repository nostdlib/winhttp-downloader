#include "ntdll.h"
#include "system.h"
#include "types.h"
#include "djb2.h"

BOOL NTDLL_Ctor(NTDLL *ntdll)
{
    if (ntdll == NULL)
        return FALSE;
    
    PVOID module;
    module = GetModuleHandleFromPEB(HashAscii("ntdll.dll"));
    if (module == NULL)
        return FALSE;

    ntdll->LdrLoadDll = (NTSTATUS (WINAPI *)(WCHAR *, UINT32, PUNICODE_STRING, PVOID *)) ResolveExportByHash(module, HashAscii("LdrLoadDll"));
    ntdll->RtlGetVersion = (NTSTATUS (WINAPI *)(PVOID)) ResolveExportByHash(module, HashAscii("RtlGetVersion"));

    return (ntdll->LdrLoadDll != NULL && ntdll->RtlGetVersion != NULL);
}
