#ifndef COMPONENT_INTERFACE_HPP
#define COMPONENT_INTERFACE_HPP


namespace Decorator
{

class ComponentInterface
{
  public:
    virtual ~ComponentInterface() = default;
    // Default c'tors and operator= overloads, both copy and move.

    virtual void behavior() = 0;
};

} // namespace Decorator


#endif // COMPONENT_INTERFACE_HPP
