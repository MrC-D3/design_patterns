#include "21_command/receiver.hpp"
#include <iostream>


namespace Command
{

void Receiver::operation()
{
    std::cout << "I'm the Receiver. I'm doing the operation.\n";
}

} // namespace Command