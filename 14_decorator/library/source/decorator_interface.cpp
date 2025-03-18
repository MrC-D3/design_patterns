#include "14_decorator/decorator_interface.hpp"


namespace Decorator
{

DecoratorInterface::DecoratorInterface(ComponentInterface* component)
    : m_component(component)
{}

void DecoratorInterface::behavior()
{
    m_component->behavior();
}

} // namespace Decorator