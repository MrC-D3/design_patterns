#ifndef COMPONENT_CONCRETE_HPP
#define COMPONENT_CONCRETE_HPP

#include "14_decorator/component_interface.hpp"

#include "iostream"


namespace Decorator
{

class ComponentConcrete final : public ComponentInterface
{
  public:
    void behavior() override
    {
        std::cout << "I'm the ComponentConcrete. This is my basic behavior." <<
          std::endl;
    }
};

} // namespace Decorator


#endif // COMPONENT_CONCRETE_HPP