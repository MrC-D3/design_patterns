#include "21_command/receiver.hpp"
#include "21_command/command_concrete.hpp"
#include "21_command/invoker.hpp"

#include <memory>


using namespace Command;

int main()
{
    Receiver receiver;
    Invoker invoker{ std::make_unique<CommandConcrete>(receiver) };

    invoker.call_command();

    return 0;
}