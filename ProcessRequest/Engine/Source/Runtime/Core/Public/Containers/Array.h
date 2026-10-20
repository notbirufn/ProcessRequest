#pragma once

#include "HAL/UnrealMemory.h"

template<typename InElementType/*, typename InAllocator*/>
class TArray
{
public:
    using SizeType = int32;
    using ElementType = InElementType;
    //using Allocator = InAllocator;

public:
    FORCEINLINE TArray()
        : ArrayNum(0)
        , ArrayMax(0)
    {
    }

public:
    FORCEINLINE ElementType* GetData()
    {
        return Data;
    }

    FORCEINLINE const ElementType* GetData() const
    {
        return Data;
    }

    FORCEINLINE uint32 GetTypeSize() const
    {
        return sizeof(ElementType);
    }

    FORCEINLINE SizeType GetSlack() const
    {
        return ArrayMax - ArrayNum;
    }

    FORCEINLINE bool IsValidIndex(SizeType Index) const
    {
        return Index >= 0 && Index < ArrayNum;
    }

    FORCEINLINE SizeType Num() const
    {
        return ArrayNum;
    }

    FORCEINLINE SizeType Max() const
    {
        return ArrayMax;
    }

    FORCEINLINE ElementType& operator[](SizeType Index)
    {
        return GetData()[Index];
    }

    FORCEINLINE const ElementType& operator[](SizeType Index) const
    {
        return GetData()[Index];
    }

    FORCEINLINE SizeType AddUninitialized(SizeType Count = 1)
    {
        const SizeType OldNum = ArrayNum;

        if ((ArrayNum += Count) > ArrayMax)
        {
            ArrayMax = ArrayNum;
            Data = (ElementType*)FMemory::Realloc(Data, ArrayMax * GetTypeSize());
        }

        return OldNum;
    }

public:
    FORCEINLINE void Reserve(SizeType Number)
    {
        if (Number > ArrayMax)
        {
            ArrayMax = Number;
            Data = (ElementType*)FMemory::Realloc(Data, ArrayMax * GetTypeSize());
        }
    }

protected:
    ElementType* Data = nullptr;
    SizeType ArrayNum;
    SizeType ArrayMax;
};
