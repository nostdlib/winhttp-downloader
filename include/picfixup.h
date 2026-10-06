#pragma once

#include "types.h"

#if defined(ENVIRONMENT_I386) && defined(PIC_RELOCATIONS_ENABLED)
    VOID PIC_ApplyFixups(UINT32 linkReturnAddress);
#else
    #define PIC_ApplyFixups() ((void)0)
#endif
