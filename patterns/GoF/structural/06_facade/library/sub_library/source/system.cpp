#include "06_facade/system.hpp"

#include <iostream>


namespace Facade
{
    
void Class1::do_something() const
{
    std::cout << "I'm Class1. I'm doing something.\n";
}

void Class2::do_something_else() const
{
    std::cout << "I'm Class2. I'm doing something else.\n";
}

} // namespace Facade