#ifndef COMPONENT_CONCRETE_HPP
#define COMPONENT_CONCRETE_HPP

#include "14_decorator/component_interface.hpp"


namespace Decorator
{

class ComponentConcrete final : public ComponentInterface
{
  public:
    ~ComponentConcrete() = default;
    ComponentConcrete() = default;

    ComponentConcrete(const ComponentConcrete& origin) = default;
    ComponentConcrete(ComponentConcrete&& origin) = default;
    ComponentConcrete& operator=(ComponentConcrete& origin) = default;
    ComponentConcrete& operator=(ComponentConcrete&& origin) = default;

    void behavior() override;
    
};

} // namespace Decorator


#endif // COMPONENT_CONCRETE_HPP