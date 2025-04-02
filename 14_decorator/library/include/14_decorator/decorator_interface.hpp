#ifndef DECORATOR_INTERFACE_HPP
#define DECORARTOR_INTERFACE_HPP

#include "14_decorator/component_interface.hpp"
#include <memory>


namespace Decorator
{

class DecoratorInterface : public ComponentInterface
{
  public:
    virtual ~DecoratorInterface() = default;
    explicit DecoratorInterface(std::unique_ptr<ComponentInterface>&& component);

    // Delete copy methods because of unique_ptr.
    DecoratorInterface(const DecoratorInterface& originator) = delete;
    DecoratorInterface& operator=(const DecoratorInterface& orginator) = delete;

    DecoratorInterface(DecoratorInterface&& originator) = default;
    DecoratorInterface& operator=(DecoratorInterface&& originator) = default;

    virtual void behavior() override;

  protected:
    std::unique_ptr<ComponentInterface> m_component;
};

} // namespace Decorator

#endif // DECORATOR_INTERFACE_HPP