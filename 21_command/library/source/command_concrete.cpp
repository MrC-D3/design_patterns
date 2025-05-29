#include "21_command/command_concrete.hpp"
#include "21_command/receiver.hpp"
#include <iostream>


namespace Command
{

CommandConcrete::CommandConcrete(const Receiver& receiver)
: m_receiver(receiver)
{}

void CommandConcrete::executeA()
{
    std::cout << "I'm a ConcreteCommand. I'll handle the request using the \
      Receiver.\n";
    m_receiver.operation1();
}

} // namespace Command