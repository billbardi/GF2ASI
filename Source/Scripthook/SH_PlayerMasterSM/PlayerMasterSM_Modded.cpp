#include "PlayerMasterSM_Modded.h"

#include "Addons/Settings.h"

// SDK
#include "SDK/EARS_Godfather/Modules/Player/Player.h"
#include "SDK/EARS_Godfather/Modules/Player/PlayerDebug.h"

#include <Windows.h>

namespace SH
{
	PlayerMasterSM_Modded::PlayerMasterSM_Modded(unsigned int id, EARS::StateMachineSys::StateMachineParams* pSMParams)
		: EARS::Modules::PlayerMasterSM(id, pSMParams)
	{
	}

	PlayerMasterSM_Modded::~PlayerMasterSM_Modded()
	{
	}

	uint32_t PlayerMasterSM_Modded::GetStateMachineID() const
	{
		// We are still considered PlayerMasterSM
		return 0xB08AE1F6;
	}

	bool PlayerMasterSM_Modded::HandleStateMessage(uint32_t SimTime, float FrameTime, uint32_t CurFlags, uint32_t MessageID, EARS::StateMachineSys::State::StateMessageData* MsgData)
	{
		if (MessageID == 0x255)
		{
			UpdateFlyMode();
			return true;
		}

		return EARS::Modules::PlayerMasterSM::HandleStateMessage(SimTime, FrameTime, CurFlags, MessageID, MsgData);
	}

	bool PlayerMasterSM_Modded::CheckTransition(uint32_t SimTime, float FrameTime, uint32_t TransID, void* TransData)
	{
		return EARS::Modules::PlayerMasterSM::CheckTransition(SimTime, FrameTime, TransID, TransData);
	}

	void PlayerMasterSM_Modded::InitialiseChild(StateMachine* ChildMachine)
	{
		EARS::Modules::PlayerMasterSM::InitialiseChild(ChildMachine);
	}

	void PlayerMasterSM_Modded::UpdateFlyMode()
	{
		const EARS::Modules::PlayerDebugOptions& DebugOptions = *EARS::Modules::PlayerDebugOptions::GetInstance();
		const bool bFlyModeActive = DebugOptions.IsInDebugFly();

		if (EARS::Modules::Player* CurPlayer = GetPlayer())
		{
			EARS::Havok::CharacterProxy& CharProxy = CurPlayer->GetCharacterProxyChecked();
			const EARS::Havok::CharacterProxy::CollisionState NewState = (bFlyModeActive ? EARS::Havok::CharacterProxy::CollisionState::CS_TRIGGERS_ONLY : EARS::Havok::CharacterProxy::CollisionState::CS_ENABLED);
			CharProxy.SetCollisionState(NewState);

			Settings& LclSettings = Settings::GetCheckedRef();

			if (bFlyModeActive)
			{
				if (GetAsyncKeyState(LclSettings.GetFlyModeUpInput()) & 0x8001)
				{
					CurPlayer->Translate(RwV3d(0.0f, 0.1f, 0.0f));
				}

				if (GetAsyncKeyState(LclSettings.GetFlyModeDownInput()) & 0x8001)
				{
					CurPlayer->Translate(RwV3d(0.0f, -0.1f, 0.0f));
				}
			}
		}
	}
}