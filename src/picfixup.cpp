#include "picfixup.h"
#include "djb2.h"

#if defined(ENVIRONMENT_I386) && defined(LOGGING_ENABLED)

#include "system.h"
#include "wintypes.h"
#include "apihash.h"

#define PIC_PAGE_EXECUTE_READWRITE 0x40
#define PIC_PAGE_EXECUTE_READ      0x20
#define PIC_RELOC_TYPE_HIGHLOW     3
#define PIC_LINK_TEXT_VMA          0x401000u

extern UINT32 pic_reloc[];
extern UINT32 pic_text_size;

VOID PIC_ApplyRelocations(UINT32 delta, const UINT32 *reloc, UINT32 textSize)
{
    BOOL (WINAPI *pVirtualProtect)(PVOID, SIZE_T, UINT32, UINT32 *);
    ULONG_PTR base = PIC_LINK_TEXT_VMA + delta;
    UINT32 scratch = 0;

    pVirtualProtect = (BOOL (WINAPI *)(PVOID, SIZE_T, UINT32, UINT32 *)) ResolveFromModuleByHash(HashAscii("kernel32.dll"), HashAscii("VirtualProtect"));
    if (pVirtualProtect == NULL)
        return;

    if (!pVirtualProtect((PVOID)base, (SIZE_T)textSize, PIC_PAGE_EXECUTE_READWRITE, &scratch))
        return;

    for (;;)
    {
        UINT32 page = reloc[0];
        UINT32 blockSize = reloc[1];
        const UINT16 *entry;
        UINT32 count;
        UINT32 i;

        if (blockSize < 8)
            break;
        count = (blockSize - 8) / 2;
        entry = (const UINT16 *)(reloc + 2);

        for (i = 0; i < count; i++)
        {
            UINT16 e = entry[i];
            if ((e >> 12) == PIC_RELOC_TYPE_HIGHLOW)
            {
                UINT32 *slot = (UINT32 *)(ULONG_PTR)(base + page + (e & 0xFFF) - 0x1000);
                *slot += delta;
            }
        }

        reloc += blockSize / 4;
    }

    pVirtualProtect((PVOID)base, (SIZE_T)textSize,
                    PIC_PAGE_EXECUTE_READ, &scratch);
}

VOID PIC_ApplyFixups(UINT32 linkReturnAddress)
{
    ULONG_PTR runtimeReturnAddress = (ULONG_PTR)__builtin_return_address(0);
    UINT32 delta = (UINT32)runtimeReturnAddress - linkReturnAddress;
    const UINT32 *reloc = (const UINT32 *)(ULONG_PTR)((ULONG_PTR)pic_reloc + delta);
    UINT32 textSize = *(const UINT32 *)(ULONG_PTR)((ULONG_PTR)&pic_text_size + delta);

    PIC_ApplyRelocations(delta, reloc, textSize);
}

#endif
