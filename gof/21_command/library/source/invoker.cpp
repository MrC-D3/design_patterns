#include "21_command/invoker.hpp"
#include "21_command/command_interface.hpp"
#include <iostream>


namespace Command
{

/*
** Implementation of the classic solution.
*/
Invoker::Invoker(std::unique_ptr<CommandInterface>&& command)
: m_command{ std::move(command) }
{}

void Invoker::call_command()
{
    std::cout << "I'm the Invoker. I'm sending the request.\n";
    m_command->executeA();

    // In case of many Commands, it can decide which one (i.e. based on player's 
    //  or AI's decision).
}

/*
** Implementation of the function-based solution.
*/
InvokerF::InvokerF(std::function<void(void)>& command)
: m_command{ command }
{}

void InvokerF::call_command()
{
    std::cout << "I'm the InvokerF. I'm invoking the command.\n";
    // In this solution there is only 1 execute(), that is the best design.
    m_command();
}

} // namespace Command