#include "06_facade/facade.hpp"
#include "06_facade/system.hpp"

#include <iostream>


namespace Facade
{
    
void Facade::do_everything() const
{
    std::cout << "I'm the Facade. I'll do everythin for you.\n";

    Class1 class1;
    class1.do_something();

    Class2 class2;
    class2.do_something_else();
}

} // namespace Facade
