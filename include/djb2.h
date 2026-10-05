#pragma once
#include "types.h"

constexpr UINT64 API_HASH_SEED = 5381ULL;

constexpr UINT64 Hash(const WCHAR* str)
{
	UINT64 hash = API_HASH_SEED;

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
	UINT64 hash = API_HASH_SEED;

	for (UINT64 index = 0; str[index] != '\0'; ++index) {
		CHAR character = str[index];
		if (character >= 'A' && character <= 'Z') {
			character = character - 'A' + 'a';
		}
		hash = ((hash << 5) + hash) + static_cast<UINT64>(static_cast<unsigned char>(character));
	}

	return hash;
}