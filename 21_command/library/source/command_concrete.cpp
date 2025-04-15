#include "21_command/command_concrete.hpp"
#include "21_command/receiver.hpp"
#include <iostream>


namespace Command
{

CommandConcrete::CommandConcrete(const Receiver& receiver)
  : m_receiver(receiver)
{}

void CommandConcrete::execute()
{
    std::cout << "I'm a ConcreteCommand. I'm forwarding the request to the \
      Receiver." << std::endl;
    m_receiver.operation();
}

} // namespace Command