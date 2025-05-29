#include "21_command/receiver.hpp"
#include <iostream>


namespace Command
{

void Receiver::operation1()
{
    std::cout << "I'm the Receiver. I'm transparent for the Invoker.\n";
}

} // namespace Command