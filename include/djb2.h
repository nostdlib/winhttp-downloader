#pragma once
#include "types.h"

constexpr UINT64 SeedGenerator(const CHAR* str){
    UINT64 h = (UINT64)2166136261u;
    for (UINT64 i = 0; str[i] != '\0'; ++i)
		h = (h ^ (UINT64)(UINT8)str[i]) * (UINT64)16777619u;
	return h;
}

static constexpr UINT64 seed = SeedGenerator(__DATE__);

constexpr UINT64 Hash(const WCHAR* str)
{
	UINT64 hash = seed;

	for (UINT64 index = 0; str[index] != L'\0'; ++index) {
		WCHAR character = str[index];
		if (character >= L'A' && character <= L'Z') {
			character = character - L'A' + L'a';
		}
		hash = ((hash << 5) + hash) + static_cast<UINT64>(character);
	}

	return hash;
}

constexpr UINT64 HashAscii(const CHAR* str)
{
	UINT64 hash = seed;

	for (UINT64 index = 0; str[index] != '\0'; ++index) {
		CHAR character = str[index];
		if (character >= 'A' && character <= 'Z') {
			character = character - 'A' + 'a';
		}
		hash = ((hash << 5) + hash) + static_cast<UINT64>(static_cast<unsigned char>(character));
	}

	return hash;
}