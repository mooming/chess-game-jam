#include <iostream>
#include <string>
#include <vector>

#include "StringHelper.h"


enum class ExecCommand : int
{
    None = 0,
    Monitor,
    Match,
    Judge,
    GameServer,
    GameClient,
    Max
};

class CommandLineArguments final
{
private:
    const std::vector<std::string> commands;

    ExecCommand command;
    std::string monitorAddress;
    std::string codeName;

public:
    CommandLineArguments()
        : commands({"None", "Monitor", "Match", "Judge", "GameServer", "GameClient"})
        , command(ExecCommand::None)
    {
    }

    void Parse(int argc, const char* argv[])
    {
        if (argc < 2)
            return;

        ParseCommand(argv[1]);

        if (command <= ExecCommand::None || command >= ExecCommand::Max)
        {

            return;
        }

        switch (command)
        {
        default:
            std::cerr << "Parse Error: Invalid command index " << static_cast<int>(command) << std::endl;
            command = ExecCommand::None;
            break;

        case ExecCommand::Monitor:
            break;

        case ExecCommand::Match:
        case ExecCommand::Judge:
        case ExecCommand::GameServer:
        case ExecCommand::GameClient:
            if (argc < 3)
            {
                monitorAddress = std::string("localhost");
            }
            else
            {
                monitorAddress = std::string(argv[2]);
            }

            break;
        }

        void Print()
        {
            using namespace std;

            Validate();
            cout << "Command: " << commands[static_cast<int>(command)];
            cout << "Monitor Address: " << monitorAddress;
        }
    }

private:

    void Validate()
    {
        if (command < ExecCommand::None || command >= ExecCommand::Max)
            command = ExecCommand::None;
    }

    void ParseCommand(const char* str)
    {
        int index = 0;

        for (auto& cmd : commands)
        {
            if (cmd == str)
            {
                command = static_cast<ExecCommand>(index);
                return;
            }

            ++index;
        }

        command = ExecCommand::None;
    }
};

namespace
{
    void PrintArguments(int argc, char* argv[])
    {
        using namespace std;

        cout << "Arguments: ";

        for (int i = 0; i < argc; ++i)
        {
            cout << "[" << i << ':' << argv[i] << "] ";
        }

        cout << endl;
    }
} // Anonymous Namespace

int main(int argc, char* argv[])
{
    using namespace std;

    string command;
    vector<string> args;

    if (argc < 2)
    {
        string executed(argc > 0 ? argv[0] : "None");
        executed = StringHelper::extractFileName(executed);

        cout << "Usage)" <<endl;
        cout << "> " << executed << " Monitor" << endl;
        cout << "> " << executed << " Match <Monitor-Address>" << endl;
        cout << "> " << executed << " Judge <Monitor-Address>" << endl;
        cout << "> " << executed << " Server <Monitor-Address>" << endl;
        cout << "> " << executed << " Client <Monitor-Address>" << endl;


        cin >> command;

    }
    else
    {
        PrintArguments(argc, argv);
        command = string(argv[1]);
    }


    return 0;
}
