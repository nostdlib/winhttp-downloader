#pragma once

#include "types.h"

#define CMD_OPEN_SHELL          0x01
#define CMD_WRITE_SHELL         0x02
#define CMD_READ_SHELL          0x03
#define CMD_CLOSE_SHELL         0x04
#define CMD_LIST_DIRECTORY      0x05
#define CMD_READ_FILE           0x06
#define CMD_HASH_FILE           0x07
#define CMD_GET_DISPLAYS        0x08
#define CMD_GET_SCREENSHOT      0x09
#define CMD_EXIT                0x0A

#define CAPABILITY_MASK_BYTES   8

#ifndef SUPPORT_SHELL
#define SUPPORT_SHELL            1
#endif

#define STATUS_OK               0
#define STATUS_ERROR            1

#define IDENTITY_FRAME_SIZE     754
#define ID_HOSTNAME_SIZE        256
#define ID_USERNAME_SIZE        256

#define ID_OS_VERSION_SIZE      128
#define AGENT_API_VERSION       1
#define AGENT_NAME_ID           5

#ifndef ID_BUILD_NUMBER
#define ID_BUILD_NUMBER         1
#endif

#define SHELL_POOL_SIZE         256
#define SHELL_READ_CHUNK        512

#define RECV_FRAGMENT_SIZE      512

#define MAX_MESSAGE_SIZE        512

#define RC_EXIT                 0

#define RC_SESSION_LOST         2

#define RC_LOCAL_ERROR          1

typedef enum {
	Capability_Shell = 0,
    CapabilityBitCount
} CapabilityBit;

typedef struct {
	UINT8 Bits[CAPABILITY_MASK_BYTES];
} CapabilityMask;


static inline VOID SetCapability(CapabilityMask *mask, CapabilityBit bit, int supported)
{
	if (supported) {
		USIZE b = (USIZE)bit;
		mask->Bits[b / 8] |= (UINT8)(1u << (b % 8));
	}
}

static inline CapabilityMask BuildCapabilityMask(VOID)
{
	CapabilityMask mask = {0};
	SetCapability(&mask, Capability_Shell, SUPPORT_SHELL);
	return mask;
}