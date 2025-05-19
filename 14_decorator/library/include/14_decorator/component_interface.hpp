#ifndef COMPONENT_INTERFACE_HPP
#define COMPONENT_INTERFACE_HPP


namespace Decorator
{

class ComponentInterface
{
  public:
    virtual ~ComponentInterface() = default;
    ComponentInterface() = default;

    ComponentInterface(const ComponentInterface& origin) = default;
    ComponentInterface(ComponentInterface&& origin) = default;
    ComponentInterface& operator=(ComponentInterface& origin) = default;
    ComponentInterface& operator=(ComponentInterface&& origin) = default;

    virtual void behavior() = 0;
};

} // namespace Decorator

#endif // COMPONENT_INTERFACE_HPP
