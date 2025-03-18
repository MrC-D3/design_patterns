#ifndef COMPONENT_CONCRETE_HPP
#define COMPONENT_CONCRETE_HPP

#include "14_decorator/component_interface.hpp"

#include "iostream"


namespace Decorator
{

class ComponentConcrete final : public ComponentInterface
{
  public:
    void behavior() override;
};

} // namespace Decorator


#endif // COMPONENT_CONCRETE_HPP