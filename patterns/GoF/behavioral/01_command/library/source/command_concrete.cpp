#include "01_command/command_concrete.hpp"
#include "01_command/receiver.hpp"
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

    // This CommandConcrete can call operation1(), another CommandConcrete can 
    //  call operation2() and so on.
    m_receiver.operation1();
}

} // namespace Command