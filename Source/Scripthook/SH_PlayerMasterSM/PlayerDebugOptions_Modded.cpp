#include "PlayerDebugOptions_Modded.h"

namespace PrivateDebug
{
	static SH::PlayerDebugOptions_Modded* StaticDebugOptions = nullptr;
}

namespace SH
{
	PlayerDebugOptions_Modded::PlayerDebugOptions_Modded()
	{
		PrivateDebug::StaticDebugOptions = this;
	}

	PlayerDebugOptions_Modded::~PlayerDebugOptions_Modded()
	{
		PrivateDebug::StaticDebugOptions = nullptr;
	}

	void PlayerDebugOptions_Modded::SetAnimViewMode(bool bIsActive)
	{
		bAnimViewMode = bIsActive;
	}

	bool PlayerDebugOptions_Modded::IsInAnimViewMode() const
	{
		return bAnimViewMode;
	}

	/** static **/
	PlayerDebugOptions_Modded* PlayerDebugOptions_Modded::GetInstance()
	{
		return PrivateDebug::StaticDebugOptions;
	}
}
