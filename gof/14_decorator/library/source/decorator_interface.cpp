#include "14_decorator/decorator_interface.hpp"


namespace Decorator
{

DecoratorInterface::DecoratorInterface(std::unique_ptr<ComponentInterface>&& component)
  : m_component(std::move(component))
{}

void DecoratorInterface::behavior()
{
    m_component->behavior();
}

} // namespace Decorator