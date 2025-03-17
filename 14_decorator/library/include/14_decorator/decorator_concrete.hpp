#ifndef DECORATOR_CONCRETE_HPP
#define DECORATOR_CONCRETE_HPP

#include "14_decorator/decorator_interface.hpp"

#include <iostream>


namespace Decorator
{

class DecoratorConcrete final : public DecoratorInterface
{
  public:
    DecoratorConcrete(ComponentInterface* component)
      : DecoratorInterface(component)
    {}

    void behavior() override
    {
        DecoratorInterface::behavior();

        std::cout << "I'm the DecoratorConcrete. I'm enriching the Component's \
          behavior with something after." << std::endl;
    }
};

} // namespace Decorator


#endif // DECORATOR_CONCRETE_HPP
