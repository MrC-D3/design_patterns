#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <memory>


namespace CompositeNS
{

class Component
{
  public:
    ~Component() = default;
    Component() = default;

    Component(const Component& origin) = default;
    Component& operator=(const Component& origin) = default;

    Component(Component&& origin) = default;
    Component& operator=(Component&& origin) = default;

    virtual void act() = 0;

    virtual void add(std::unique_ptr<Component>&& child);
};

} // namespace CompositeNS


#endif // COMPONENT_HPP