#include "14_decorator/decorator_concrete.hpp"
#include <iostream>


namespace Decorator
{

DecoratorConcrete::DecoratorConcrete(std::unique_ptr<ComponentInterface>&& component)
  : DecoratorInterface( std::move(component) )
{}

void DecoratorConcrete::behavior()
{
    DecoratorInterface::behavior();

    std::cout << "I'm the DecoratorConcrete. I'm enriching the Component's \
        behavior with something after.\n";
}

} // namespace Decorator
