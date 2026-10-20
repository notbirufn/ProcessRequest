#pragma once

#include "GenericPlatform/GenericPlatformStricmp.h"
#include "HAL/Platform.h"

struct FGenericPlatformString : public FGenericPlatformStricmp
{
	template <typename SourceEncoding, typename DestEncoding>
	static FORCEINLINE DestEncoding* Convert(DestEncoding* Dest, int32 DestSize, const SourceEncoding* Src, int32 SrcSize)
	{
		/*if (DestSize < SrcSize)
		{
			return nullptr;
		}

		return (DestEncoding*)Memcpy(Dest, Src, SrcSize * sizeof(SourceEncoding)) + SrcSize;*/

		const int32 Size = DestSize <= SrcSize ? DestSize : SrcSize;
		for (int I = 0; I < Size; ++I)
		{
			SourceEncoding SrcCh = Src[I];
			Dest[I] = (DestEncoding)SrcCh;
		}

		return DestSize < SrcSize ? nullptr : Dest + Size;
	}

	template <typename DestEncoding, typename SourceEncoding>
	static int32 ConvertedLength(const SourceEncoding* Src)
	{
		int32 Result = 0;

		while (*Src)
		{
			++Src;
			++Result;
		}

		return Result + 1;
	}

	template <typename DestEncoding, typename SourceEncoding>
	static int32 ConvertedLength(const SourceEncoding* Src, int32 SrcSize)
	{
		return SrcSize;
	}


private:
	static void* Memcpy(void* Dest, const void* Src, SIZE_T Count);
};
