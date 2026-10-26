#pragma once

#include "Misc/EngineVersionBase.h"
#include "Containers/UnrealString.h"

class FEngineVersion : public FEngineVersionBase
{
	const FString& GetBranchDescriptor() const;

private:
	FString Branch;
};
