#pragma once

// SDK
#include "SDK/EARS_Common/Array.h"
#include "SDK/EARS_Common/Singleton.h"
#include "SDK/EARS_Framework/Core/AttributeHandler/CAttributeHandler.h"

namespace EARS
{
	namespace Modules
	{
		class UpgradeData : public RWS::CAttributeHandler
		{
		public:

		};

		class UpgradeManager : public Singleton<UpgradeManager>
		{
		public:

			Array<EARS::Modules::UpgradeData*> m_UpgradeList[6];
		};
	}
}
