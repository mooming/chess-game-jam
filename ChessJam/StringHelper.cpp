#include "StringHelper.h"


std::string StringHelper::extractFileName(const std::string path)
{
    auto found = path.find_last_of('/');
    if (found != std::string::npos)
    {
        return path.substr(found + 1);
    }

    found = path.find_last_of('\\');
    if (found != std::string::npos)
    {
        return path.substr(found + 1);
    }

    return path;
}
