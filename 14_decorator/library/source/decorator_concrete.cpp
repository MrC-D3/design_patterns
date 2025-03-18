#include "14_decorator/decorator_concrete.hpp"


namespace Decorator
{

DecoratorConcrete::DecoratorConcrete(ComponentInterface* component)
  : DecoratorInterface(component)
{}

void DecoratorConcrete::behavior()
{
    DecoratorInterface::behavior();

    std::cout << "I'm the DecoratorConcrete. I'm enriching the Component's \
        behavior with something after." << std::endl;
}

} // namespace Decorator
