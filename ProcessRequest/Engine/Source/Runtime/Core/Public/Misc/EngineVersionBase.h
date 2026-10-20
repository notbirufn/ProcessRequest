#pragma once

#include "HAL/Platform.h"

enum class EVersionComponent
{
	Major,
	Minor,
	Patch,
	Changelist,
	Branch,
};

class FEngineVersionBase
{
public:
	uint32 GetChangelist() const;

	FORCEINLINE uint16 GetMajor() const
	{
		return Major;
	}

	FORCEINLINE uint16 GetMinor() const
	{
		return Minor;
	}

	FORCEINLINE uint16 GetPatch() const
	{
		return Patch;
	}

	bool IsLicenseeVersion() const;

	bool IsEmpty() const;

	bool HasChangelist() const;

protected:
	uint16 Major = 0;
	uint16 Minor = 0;
	uint16 Patch = 0;
	uint32 Changelist = 0;
};
