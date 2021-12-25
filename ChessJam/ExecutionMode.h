#pragma once

#include <string>
#include <vector>

enum class ExecutionMode : int
{
    None = 0,
    Monitor,
    Match,
    Judge,
    GameServer,
    GameClient,
    Max
};

namespace ExecutionModeHelper
{
    const std::vector<std::string>& GetNames();
}
