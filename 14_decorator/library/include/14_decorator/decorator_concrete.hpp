#ifndef DECORATOR_CONCRETE_HPP
#define DECORATOR_CONCRETE_HPP

#include "14_decorator/decorator_interface.hpp"

#include <iostream>


namespace Decorator
{

class DecoratorConcrete final : public DecoratorInterface
{
  public:
    DecoratorConcrete(ComponentInterface* component);

    void behavior() override;
};

} // namespace Decorator


#endif // DECORATOR_CONCRETE_HPP
