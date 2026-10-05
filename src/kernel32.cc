#include "kernel32.h"
#include "system.h"
#include "wintypes.h"

BOOL KERNEL32_Ctor(KERNEL32 *kernel)
{
    PVOID module;

    if (kernel == NULL)
        return FALSE;

    module = GetModuleHandleFromPEB(HashAscii("kernel32.dll"));
    if (module == NULL)
        return FALSE;

    kernel->GetProcAddress = (PVOID (WINAPI *)(PVOID, const CHAR *))
        ResolveExportByHash(module, HashAscii("GetProcAddress"));
    kernel->LoadLibraryA = (PVOID (WINAPI *)(const CHAR *))
        ResolveExportByHash(module, HashAscii("LoadLibraryA"));
    kernel->GetComputerNameA = (BOOL (WINAPI *)(PCHAR, DWORD *))
        ResolveExportByHash(module, HashAscii("GetComputerNameA"));
    kernel->SetHandleInformation = (BOOL (WINAPI *)(HANDLE, DWORD, DWORD))
        ResolveExportByHash(module, HashAscii("SetHandleInformation")); 
    kernel->CreateProcessW = (BOOL (WINAPI *)(const PWCHAR, const PWCHAR, LPSECURITY_ATTRIBUTES, LPSECURITY_ATTRIBUTES, BOOL, DWORD, PVOID, const PWCHAR, LPSTARTUPINFOW, LPPROCESS_INFORMATION))
        ResolveExportByHash(module, HashAscii("CreateProcessW"));
    kernel->CloseHandle = (BOOL (WINAPI *)(HANDLE))
        ResolveExportByHash(module, HashAscii("CloseHandle"));
    kernel->TerminateProcess = (BOOL (WINAPI *)(HANDLE, UINT32))
        ResolveExportByHash(module, HashAscii("TerminateProcess"));
    kernel->WriteFile = (BOOL (WINAPI *)(HANDLE, const void *, DWORD, DWORD *, PVOID))
        ResolveExportByHash(module, HashAscii("WriteFile"));
    kernel->ReadFile = (BOOL (WINAPI *)(HANDLE, void *, DWORD, DWORD *, PVOID))
        ResolveExportByHash(module, HashAscii("ReadFile"));
    kernel->PeekNamedPipe = (BOOL (WINAPI *)(HANDLE, void *, DWORD, DWORD *, DWORD *, DWORD *))
        ResolveExportByHash(module, HashAscii("PeekNamedPipe"));
    kernel->CreatePipe = (BOOL (WINAPI *)(HANDLE *, HANDLE *, LPSECURITY_ATTRIBUTES, DWORD))
        ResolveExportByHash(module, HashAscii("CreatePipe"));
    kernel->GetStdHandle = (HANDLE (WINAPI *)(DWORD))
        ResolveExportByHash(module, HashAscii("GetStdHandle"));
    kernel->GetLastError = (DWORD (WINAPI *)(void))
        ResolveExportByHash(module, HashAscii("GetLastError"));
    kernel->Sleep = (void (WINAPI *)(DWORD))
        ResolveExportByHash(module, HashAscii("Sleep"));
    kernel->ExitProcess = (void (WINAPI *)(UINT32))
        ResolveExportByHash(module, HashAscii("ExitProcess"));

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
