#pragma once

#include "HAL/Platform.h"
#include "HAL/PlatformMemory.h"
#include "HAL/MemoryBase.h"

struct FMemory
{
	static FORCEINLINE void* Memmove(void* Dest, const void* Src, SIZE_T Count)
	{
		return FPlatformMemory::Memmove(Dest, Src, Count);
	}

	static FORCEINLINE int32 Memcmp(const void* Buf1, const void* Buf2, SIZE_T Count)
	{
		return FPlatformMemory::Memcmp(Buf1, Buf2, Count);
	}

	static FORCEINLINE void* Memset(void* Dest, uint8 Char, SIZE_T Count)
	{
		return FPlatformMemory::Memset(Dest, Char, Count);
	}

	template< class T >
	static FORCEINLINE void Memset(T& Src, uint8 ValueToSet)
	{
		Memset(&Src, ValueToSet, sizeof(T));
	}

	static FORCEINLINE void* Memzero(void* Dest, SIZE_T Count)
	{
		return FPlatformMemory::Memzero(Dest, Count);
	}

	static FORCEINLINE bool MemIsZero(const void* Ptr, SIZE_T Count)
	{
		uint8* Start = (uint8*)Ptr;
		uint8* End = Start + Count;

		while (Start < End)
		{
			if ((*Start++) != 0)
			{
				return false;
			}
		}

		return true;
	}

	template< class T >
	static FORCEINLINE void Memzero(T& Src)
	{
		Memzero(&Src, sizeof(T));
	}

	static FORCEINLINE void* Memcpy(void* Dest, const void* Src, SIZE_T Count)
	{
		return FPlatformMemory::Memcpy(Dest, Src, Count);
	}

	template< class T >
	static FORCEINLINE void Memcpy(T& Dest, const T& Src)
	{
		Memcpy(&Dest, &Src, sizeof(T));
	}


	UE_ALLOCATION_FUNCTION(1, 2) static void* Malloc(SIZE_T Count, uint32 Alignment = DEFAULT_ALIGNMENT);
	UE_ALLOCATION_FUNCTION(2, 3) static void* Realloc(void* Original, SIZE_T Count, uint32 Alignment = DEFAULT_ALIGNMENT);

	static void Free(void* Original);
};
