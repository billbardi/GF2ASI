#include "MadeMan.h"

// SDK
#include "SDK/EARS_Godfather/Modules/Families/Family.h"
#include "SDK/EARS_Godfather/Modules/Sentient/SentientConstants.h"
#include "SDK/EARS_Godfather/Modules/NPCScheduling/SimNPC.h"

// CPP
#include "Addons/Hook.h"

namespace EARS
{
    namespace Modules
    {
        void MadeMan::SetState(MadeManState DesiredState, const float CooldownSec)
        {
            MemUtils::CallClassMethod<void, MadeMan*, MadeManState, const float>(0x08C8A20, this, DesiredState, CooldownSec);
        }

        void MadeMan::SetVenueID(const uint32_t InVenueID)
        {
            MemUtils::CallClassMethod<void, MadeMan*, uint32_t>(0x0790D30, this, InVenueID);
        }

        void MadeMan::ReleaseFromVenue(MadeManState DesiredState)
        {
            MemUtils::CallClassMethod<void, MadeMan*, MadeManState>(0x08C8A80, this, DesiredState);
        }

        EARS::Modules::SentientRank EARS::Modules::MadeMan::GetRank() const
        {
            assert(m_SimNPC && "Expects SimNPC");

            return m_SimNPC->GetRank();
        }

        float MadeMan::GetHospitalTime() const
        {
            assert(m_Family);
        
            return m_Family->GetMadeManHospitalTime() * GetHospitalTimeFactor();
        }

        float MadeMan::GetJailTime() const
        {
            assert(m_Family);

            return m_Family->GetMadeManJailTime() * GetJailTimeFactor();
        }

        const char* MadeMan::StateEnumToString(MadeManState State)
        {
            static const char* StringStates[9]
            {
                "HIDDEN",
                "IDLE",
                "IN_COMBAT",
                "IN_COOLDOWN",
                "IN_TRANSIT",
                "IN_HOSPITAL",
                "IN_JAIL",
                "ELIMINATED",
                "CREW_UI_ONLY",
            };

            return StringStates[State];
        }
    }
}
