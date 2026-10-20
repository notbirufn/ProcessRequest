#include "GenericPlatform/GenericPlatformString.h"
#include "HAL/UnrealMemory.h"

void* FGenericPlatformString::Memcpy(void* Dest, const void* Src, SIZE_T Count)
{
	return FMemory::Memcpy(Dest, Src, Count);
}
