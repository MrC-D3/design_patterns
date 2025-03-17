#ifndef COMPONENT_INTERFACE_HPP
#define COMPONENT_INTERFACE_HPP


namespace Decorator
{

class ComponentInterface
{
  public:
    virtual ~ComponentInterface() = default;

    virtual void behavior() = 0;
};

} // namespace DecoratorInterace

#endif // COMPONENT_INTERFACE_HPP
