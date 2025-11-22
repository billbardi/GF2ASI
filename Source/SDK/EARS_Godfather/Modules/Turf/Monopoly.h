#pragma once

// SDK (Common)
#include "SDK/EARS_Common/Array.h"
#include "SDK/EARS_Common/String.h"

namespace EARS
{
	namespace Modules
	{
		class BuildingStore;

		class MonopolyData
		{
			int z = 0;
		};

		class Monopoly
		{
		public:

			String* GetDisplayName();

			String* GetPerkDescription();

		private:

			struct OwnerShare
			{
				uint32_t m_FamilyID = 0;

				uint32_t m_NumOwned = 0;
			};

			const EARS::Modules::MonopolyData* m_MonopolyData = nullptr;

			Array<EARS::Modules::BuildingStore*> m_Stores;

			Array<OwnerShare> m_Shares;

			String m_DisplayName;

			String m_PerkDescription;
		};
	}
}
