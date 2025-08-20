#include "01_command/receiver.hpp"
#include "01_command/command_concrete.hpp"
#include "01_command/invoker.hpp"

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
    // If use "auto", it would be a lambda, so not explicitly a std::function.
    // So, passing it to Invoker(std::function<>&) creates a temporary object.
    // Since it'd be an rvalue and not an lvalue, the build fails.
    std::function<void()> f = [&receiver](){
      std::cout << "I'm the Command. Request managed using the Receiver.\n";
      receiver.operation1();
    };
    InvokerF invokerF{f};

    return 0;
}