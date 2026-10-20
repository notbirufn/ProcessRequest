#pragma once

#include "Containers/Array.h"
#include "Misc/CString.h"

class FString
{
private:
    typedef TArray<TCHAR> DataType;
    DataType Data;

public:
    FString() = default;

    FString(FString&&) = default;
    FString(const FString&) = default;

    FString& operator=(FString&&) = default;
    FString& operator=(const FString&) = default;

    FORCEINLINE FString(const TCHAR* Src)
    {
        if (Src && *Src)
        {
            int32 SrcLen = FCString::Strlen(Src) + 1;
            int32 DestLen = FPlatformString::ConvertedLength<TCHAR>(Src, SrcLen);

            Data.Reserve(DestLen);
            Data.AddUninitialized(DestLen);

            FMemory::Memcpy(Data.GetData(), Src, SrcLen * Data.GetTypeSize());
        }
    }

public:
    FORCEINLINE bool IsEmpty() const
    {
        return Data.Num() <= 1;
    }

    FORCEINLINE const TCHAR* operator*() const
    {
        return Data.Num() != 0 ? Data.GetData() : TEXT("");
    }

    FORCEINLINE DataType& GetCharArray() UE_LIFETIMEBOUND
    {
        return Data;
    }

    FORCEINLINE const DataType& GetCharArray() const UE_LIFETIMEBOUND
    {
        return Data;
    }

    FORCEINLINE FString& operator+=(const TCHAR* Str)
    {
        if (!Str)
            return *this;

        int32 Count = FCString::Strlen(Str);

        if (Count < 1)
            return *this;

        const int32 OldNum = Data.Num();
        Data.AddUninitialized(Count + (OldNum ? 0 : 1));

        TCHAR* Dest = Data.GetData() + OldNum - (OldNum ? 1 : 0);
        FPlatformString::Convert(Dest, Count, Str, Count);
        Dest[Count] = '\0';

        return *this;
    }

public:
    FORCEINLINE bool operator==(const TCHAR* Other) const
    {
        return FCString::Strcmp(operator*(), Other) == 0;
    }

    FORCEINLINE bool operator!=(const TCHAR* Other) const
    {
        return FCString::Strcmp(operator*(), Other) != 0;
    }

    FORCEINLINE int32 Len() const
    {
        return Data.Num() ? Data.Num() - 1 : 0;
    }
};
