#pragma once

// CCT
#include "ChrCntrl_Transform.h"

// CPP
#include <stdint.h>

// forward declares
struct ChrCntl_AnimNode_s;

namespace EA
{
	namespace CCT
	{
		namespace Internal
		{
			class AnimState
			{
			public:

				virtual ~AnimState() { /* filled in by game code */ }

				/** Add Flags to the AnimState instance */
				void SetFlags(int32_t InFlags);

				/** Remove Flags from the AnimState instance */
				void ClearFlags(int32_t InFlags);

				// getters
				uint32_t GetStateId() const { return m_StateID; }
				float GetFrameNum() const { return m_FrameNum; }
				float GetNumFrames() const { return m_NumFrames; }

			protected:

				char pad_0000[12]; //0x0000
				int32_t m_Flags = 0; // 0x0010
				uint32_t m_StateID = 0; //0x0014
				uint32_t m_RootStateID = 0; //0x0018
				float m_FrameNum = 0.0f; //0x001C
				float m_PrevFrameNum = 0.0f; //0x0020
				float m_NumFrames = 0.0f; //0x0024
				float m_PrevNumFrames = 0.0f; //0x0028
				int32_t m_BlendOutMode = 0; //0x002C
				char pad_0030[16]; //0x0030
				EA::CCT::Transform m_CarryOver; // m_gmCarryOver
				const ChrCntl_AnimNode_s* m_AnimTree; //0x0060
				void* m_InstVars; //0x0064
				void* m_NodeToUpdate; //0x0068
				char m_AnimState_padding_1[4];

			};
		}
	} // CCT
} // EARS
