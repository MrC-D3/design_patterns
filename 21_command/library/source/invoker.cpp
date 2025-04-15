#include "21_command/invoker.hpp"
#include "21_command/command_interface.hpp"
#include <iostream>


namespace Command
{

Invoker::Invoker(CommandInterface* command)
  : m_command(command)
{}

void Invoker::call_command()
{
    std::cout << "I'm the Invoker. I'm sending the request." << std::endl;
    m_command->execute();
}

} // namespace Command