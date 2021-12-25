#pragma once

#include <string>
#include <vector>

#include "ExecutionMode.h"


class CommandLineInput final
{
private:
    ExecutionMode executionMode;
    std::string monitorAddress;
    std::string codeName;

public:
    CommandLineInput();
    ~CommandLineInput() = default;

    bool isValid() const;
    void parse(int argc, const char* argv[]);
    void print() const;

private:
    void validate();
    void parseCommand(const char* str);
};

