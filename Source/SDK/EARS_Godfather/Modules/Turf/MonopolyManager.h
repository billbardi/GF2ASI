#pragma once

// SDK (Common)
#include "SDK/EARS_Common/Array.h"
#include "SDK/EARS_Common/Singleton.h"

namespace EARS
{
	namespace Modules
	{
		// foward declare
		class Monopoly;

		class MonopolyManager : public Singleton<MonopolyManager>
		{
		public:

			virtual ~MonopolyManager() { /* implemented in game */ }

			// Get the MonopolyManager instance
			static MonopolyManager* GetInstance();

		//private:

			bool m_bMessagesEnabled = false;

			Array<EARS::Modules::Monopoly*> m_Monopolies;
		};
	}
}
