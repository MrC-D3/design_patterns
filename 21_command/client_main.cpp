#include "21_command/receiver.hpp"
#include "21_command/command_concrete.hpp"
#include "21_command/invoker.hpp"

#include <memory>


using namespace Command;

int main()
{
    Receiver receiver;
    auto command = std::make_unique<CommandConcrete>(receiver);
    Invoker invoker(std::move(command));

    invoker.call_command();

    return 0;
}