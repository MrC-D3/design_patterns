#include "21_command/receiver.hpp"
#include "21_command/command_concrete.hpp"
#include "21_command/invoker.hpp"


using namespace Command;

int main()
{
    Receiver receiver;
    CommandConcrete command(receiver);
    Invoker invoker(&command);

    invoker.call_command();

    return 0;
}