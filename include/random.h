#pragma once

#include "uuid.h"
#include "system.h"
#include "djb2.h"

class Random{
    public:
        Random() = default;
        UINT64 state = 0;
        
        constexpr Random(UINT64 seed) : state(seed) {}
        VOID Seed(UINT64 seed) {
            state = seed;
        }

        VOID EnsureSeeded();

        constexpr inline INT32 Get(){
                state ^= state << 13;
                state ^= state >> 7;
                state ^= state << 17;
                return static_cast<INT32>(state & 0x7FFFFFFF);
            }

        VOID GetArray(PVOID buffer, DWORD size){
            EnsureSeeded();
            for(int i = 0; i < size; i++)
                ((UINT8*)buffer)[i] = static_cast<UINT8>(Get() & 0xFF);
        }

        UUID RandomUUID(){
            UINT8 bytes[16];
            GetArray(bytes, 16);
            bytes[6] = (bytes[6] & 0x0F) | 0x40; // Set version to 4
            bytes[8] = (bytes[8] & 0x3F) | 0x80; // Set variant to 10
            return UUID(bytes);
        }
};
