#include "10_facade/facade.hpp"
#include "10_facade/system.hpp"

#include <iostream>


void Facade::do_everything()
{
    std::cout << "I'm the Facade. I'll do everythin for you." << std::endl;

    Class1 class1;
    class1.do_something();

    Class2 class2;
    class2.do_something_else();
}