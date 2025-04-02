#include "14_decorator/component_concrete.hpp"
#include <iostream>


namespace Decorator
{

void ComponentConcrete::behavior()
{
    std::cout << "I'm the ComponentConcrete. This is my basic behavior." <<
        std::endl;
}

} // namespace Decorator