#pragma once

#include "SDK/EARS_Framework/Core/EventHandler/CEventHandler.h"

namespace EARS
{
	namespace Modules
	{
		struct ISimNPCListener
		{

		};

		class BuildingStore : public ISimNPCListener, public RWS::CEventHandler
		{
		public:

		private:
		};
	}
}