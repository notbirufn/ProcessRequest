#pragma once

#include "Misc/EngineVersionBase.h"
#include "Containers/UnrealString.h"

class FEngineVersion : public FEngineVersionBase
{
public:
	static const FEngineVersion& Current();

	const FString& GetBranchDescriptor() const;

private:
	FString Branch;
};
