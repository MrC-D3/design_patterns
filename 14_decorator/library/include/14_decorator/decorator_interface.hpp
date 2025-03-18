#ifndef DECORATOR_INTERFACE_HPP
#define DECORARTOR_INTERFACE_HPP

#include "14_decorator/component_interface.hpp"


namespace Decorator
{

class DecoratorInterface : public ComponentInterface
{
  public:
    virtual ~DecoratorInterface() = default;

    DecoratorInterface(ComponentInterface* component);

    virtual void behavior() override;

  protected:
    ComponentInterface* m_component;
};

} // namespace Decorator

#endif // DECORATOR_INTERFACE_HPP