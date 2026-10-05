#pragma once
#include "types.h"
#include <stdarg.h>

INT32 AnsiToWide(const CHAR *ansi, PWCHAR wide, INT32 wideSize);
BOOL AsciiEquals(const CHAR *left, const CHAR *right);
USIZE strlen(const CHAR *s);
USIZE wcslen(const WCHAR *s);
INT32 Format(PCHAR s, SIZE_T size, const CHAR* format, ...);

