#include "SDK/EARS_RT_CCT/include/ChrCntrl_Character.h"

namespace EA
{
	namespace CCT
	{
		const char* Character_GetStateName(const ChrCntl_ChrInfo_s& InCharacter, const uint32_t ID)
		{
			if (const CCTNameNode* Node = InCharacter.m_NameNodeHash->Lookup(ID))
			{
				return Node->GetName();
			}

			return nullptr;
		}

		const ChrCntl_AnimNode_s* Character_GetStateNode(const ChrCntl_ChrInfo_s& InCharacter, const uint32_t ID)
		{
			if (const CCTNameNode* Node = InCharacter.m_NameNodeHash->Lookup(ID))
			{
				return Node->GetNode();
			}

			return nullptr;
		}

		uint32_t Character_CountStateNodes(const ChrCntl_ChrInfo_s& InCharacter)
		{
			return InCharacter.m_NameNodeHash->Size();
		}

		uint32_t Character_CountStateNames(const ChrCntl_ChrInfo_s& InCharacter)
		{
			return InCharacter.m_NameNodeHash->Size();
		}
	} // CCT
} // EA
