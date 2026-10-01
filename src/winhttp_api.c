#include "winhttp_api.h"
#include "system.h"
#include "ntdll.h"
#include "stackstrings.h"
#include "djb2.h"

static PVOID GetWinHttp()
{
    PVOID base = GetModuleHandleFromPEB(Hash((WCHAR[]){L'w', L'i', L'n', L'h', L't', L't', L'p', L'.', L'd', L'l', L'l', L'\0'}));
    if (base != NULL)
        return base;

    NTDLL ntdll;
    if (!NTDLL_Ctor(&ntdll) || ntdll.LdrLoadDll == NULL)
        return NULL;

    WCHAR nameBuf[12];
    BuildWinHttpDllName(nameBuf);

    UNICODE_STRING name;
    name.Length        = STRLEN_BYTES_WINHTTP;
    name.MaximumLength = STRLEN_BYTES_WINHTTP + 2;
    name.Buffer        = nameBuf;

    PVOID loaded = NULL;
    if (ntdll.LdrLoadDll(NULL, 0, &name, &loaded) != 0 || loaded == NULL)
        return NULL;

    return loaded;
}

BOOL WINHTTP_API_Ctor(WINHTTP_API *api)
{
    if (api == NULL)
        return FALSE;

    PVOID winhttp = GetWinHttp();

    if (winhttp == NULL)
        return FALSE;

    api->WinHttpCrackUrl = (BOOL (WINAPI *)(const WCHAR *, DWORD, DWORD, URL_COMPONENTS *))
                            ResolveExportByHash(winhttp, Hash((WCHAR[]){L'W', L'i', L'n', L'H', L't', L't', L'p', L'C', L'r', L'a', L'c', L'k', L'U', L'r', L'l', L'\0'}));
    api->WinHttpWebSocketSend = (DWORD (WINAPI *)(HINTERNET, WINHTTP_WEB_SOCKET_BUFFER_TYPE, PVOID, DWORD))
                            ResolveExportByHash(winhttp, Hash((WCHAR[]){L'W', L'i', L'n', L'H', L't', L't', L'p', L'W', L'e', L'b', L'S', L'o', L'c', L'k', L'e', L't', L'S', L'e', L'n', L'd', L'\0'}));
    api->WinHttpWebSocketReceive = (DWORD (WINAPI *)(HINTERNET, PVOID, DWORD, DWORD *, WINHTTP_WEB_SOCKET_BUFFER_TYPE *))
                            ResolveExportByHash(winhttp, Hash((WCHAR[]){L'W', L'i', L'n', L'H', L't', L't', L'p', L'W', L'e', L'b', L'S', L'o', L'c', L'k', L'e', L't', L'R', L'e', L'c', L'e', L'i', L'v', L'e', L'\0'}));
    api->WinHttpOpen = (HINTERNET (WINAPI *)(const WCHAR *, DWORD, const WCHAR *, const WCHAR *, DWORD))
                            ResolveExportByHash(winhttp, Hash((WCHAR[]){L'W', L'i', L'n', L'H', L't', L't', L'p', L'O', L'p', L'e', L'n', L'\0'}));
    api->WinHttpConnect = (HINTERNET (WINAPI *)(HINTERNET, const WCHAR *, UINT16, DWORD))
                            ResolveExportByHash(winhttp, Hash((WCHAR[]){L'W', L'i', L'n', L'H', L't', L't', L'p', L'C', L'o', L'n', L'n', L'e', L'c', L't', L'\0'}));
    api->WinHttpOpenRequest = (HINTERNET (WINAPI *)(HINTERNET, const WCHAR *, const WCHAR *, WCHAR *, const WCHAR *, WCHAR **, DWORD))
                            ResolveExportByHash(winhttp, Hash((WCHAR[]){L'W', L'i', L'n', L'H', L't', L't', L'p', L'O', L'p', L'e', L'n', L'R', L'e', L'q', L'u', L'e', L's', L't', L'\0'}));
    api->WinHttpSetOption = (BOOL (WINAPI *)(HINTERNET, DWORD, PVOID, DWORD))
                            ResolveExportByHash(winhttp, Hash((WCHAR[]){L'W', L'i', L'n', L'H', L't', L't', L'p', L'S', L'e', L't', L'O', L'p', L't', L'i', L'o', L'n', L'\0'}));
    api->WinHttpSendRequest = (BOOL (WINAPI *)(HINTERNET, const WCHAR *, DWORD, PVOID, DWORD, DWORD, ULONG_PTR))
                            ResolveExportByHash(winhttp, Hash((WCHAR[]){L'W', L'i', L'n', L'H', L't', L't', L'p', L'S', L'e', L'n', L'd', L'R', L'e', L'q', L'u', L'e', L's', L't', L'\0'}));
    api->WinHttpReceiveResponse = (BOOL (WINAPI *)(HINTERNET, PVOID))
                            ResolveExportByHash(winhttp, Hash((WCHAR[]){L'W', L'i', L'n', L'H', L't', L't', L'p', L'R', L'e', L'c', L'e', L'i', L'v', L'e', L'R', L'e', L's', L'p', L'o', L'n', L's', L'e', L'\0'}));
    api->WinHttpWebSocketCompleteUpgrade = (HINTERNET (WINAPI *)(HINTERNET, ULONG_PTR))
                            ResolveExportByHash(winhttp, Hash((WCHAR[]){L'W', L'i', L'n', L'H', L't', L't', L'p', L'W', L'e', L'b', L'S', L'o', L'c', L'k', L'e', L't', L'C', L'o', L'm', L'p', L'l', L'e', L't', L'e', L'U', L'p', L'g', L'r', L'a', L'd', L'e', L'\0'}));
    api->WinHttpCloseHandle = (BOOL (WINAPI *)(HINTERNET))
                            ResolveExportByHash(winhttp, Hash((WCHAR[]){L'W', L'i', L'n', L'H', L't', L't', L'p', L'C', L'l', L'o', L's', L'e', L'H', L'a', L'n', L'd', L'l', L'e', L'\0'}));

    return (api->WinHttpCrackUrl != NULL &&
            api->WinHttpWebSocketSend != NULL &&
            api->WinHttpWebSocketReceive != NULL &&
            api->WinHttpOpen != NULL &&
            api->WinHttpConnect != NULL &&
            api->WinHttpOpenRequest != NULL &&
            api->WinHttpSetOption != NULL &&
            api->WinHttpSendRequest != NULL &&
            api->WinHttpReceiveResponse != NULL &&
            api->WinHttpWebSocketCompleteUpgrade != NULL &&
            api->WinHttpCloseHandle != NULL);
}
