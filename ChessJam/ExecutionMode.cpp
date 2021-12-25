#include "ExecutionMode.h"


namespace ExecutionModeHelper
{

    const std::vector<std::string>& GetNames()
    {
        using TNames = const std::vector<std::string>;
        static TNames names({ "None","Monitor", "Match",
            "Judge", "GameServer", "GameClient" });

        return names;
    }

} // ExecutionModeHelper
