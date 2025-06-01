#include "MadeMan.h"

// SDK
#include "SDK/EARS_Godfather/Modules/Sentient/SentientConstants.h"
#include "SDK/EARS_Godfather/Modules/NPCScheduling/SimNPC.h"

namespace EARS
{
    namespace Modules
    {
        EARS::Modules::SentientRank EARS::Modules::MadeMan::GetRank() const
        {
            assert(m_SimNPC && "Expects SimNPC");

            return m_SimNPC->GetRank();
        }
    }
}
