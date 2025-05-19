#include "21_command/invoker.hpp"
#include "21_command/command_interface.hpp"
#include <iostream>


namespace Command
{

Invoker::Invoker(std::unique_ptr<CommandInterface>&& command)
  : m_command(std::move(command))
{}

void Invoker::call_command()
{
    std::cout << "I'm the Invoker. I'm sending the request.\n";
    m_command->execute();
}

} // namespace Command