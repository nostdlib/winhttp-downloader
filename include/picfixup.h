#include "types.h"

#if defined(ENVIRONMENT_I386) && defined(PIC_RELOCATIONS_ENABLED)
    #ifdef __cplusplus
    extern "C" {
    #endif
    VOID PIC_ApplyFixups(VOID);
    #ifdef __cplusplus
    }
    #endif
#else
    #define PIC_ApplyFixups() ((void)0)
#endif