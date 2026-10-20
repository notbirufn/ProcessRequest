#include "Misc/EngineVersion.h"

uint32 FEngineVersionBase::GetChangelist() const
{
	return Changelist & (uint32)0x7fffffffU;
}

bool FEngineVersionBase::IsLicenseeVersion() const
{
	return (Changelist & (uint32)0x80000000U) != 0;
}

bool FEngineVersionBase::IsEmpty() const
{
	return Major == 0 && Minor == 0 && Patch == 0;
}

bool FEngineVersionBase::HasChangelist() const
{
	return GetChangelist() != 0;
}

const FString& FEngineVersion::GetBranchDescriptor() const
{
	return Branch;
}
