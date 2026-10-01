#include "ntdll.h"
#include "system.h"
#include "types.h"
#include "djb2.h"

BOOL NTDLL_Ctor(NTDLL *ntdll)
{
    if (ntdll == NULL)
        return FALSE;
    
    PVOID module;
    module = GetModuleHandleFromPEB(Hash((WCHAR[]){L'n', L't', L'd', L'l', L'l', L'.', L'd', L'l', L'l', L'\0'}));
    if (module == NULL)
        return FALSE;

    ntdll->LdrLoadDll = (NTSTATUS (WINAPI *)(WCHAR *, UINT32, PUNICODE_STRING, PVOID *))
        ResolveExportByHash(module, Hash((WCHAR[]){L'L', L'd', L'r', L'L', L'o', L'a', L'd', L'D', L'l', L'l', L'\0'}));
    ntdll->RtlGetVersion = (NTSTATUS (WINAPI *)(PVOID))
        ResolveExportByHash(module, Hash((WCHAR[]){L'R', L't', L'l', L'G', L'e', L't', L'V', L'e', L'r', L's', L'i', L'o', L'n', L'\0'}));

    return (ntdll->LdrLoadDll != NULL && ntdll->RtlGetVersion != NULL);
}
