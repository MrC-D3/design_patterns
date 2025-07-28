#include "21_command/receiver.hpp"
#include "21_command/command_concrete.hpp"
#include "21_command/invoker.hpp"

#include <memory>
#include <iostream>


int main()
{
    using namespace Command;

    /*
    ** Classic solution.
    */
    Receiver receiver;
    Invoker invoker{ std::make_unique<CommandConcrete>(receiver) };
    invoker.call_command();

    /*
    ** Function-based solution.
    */
    InvokerF invokerF{
      [&receiver](){
        std::cout << "I'm the Command. Request managed using the Receiver.\n";
        receiver.operation1();
      }
    };

    return 0;
}