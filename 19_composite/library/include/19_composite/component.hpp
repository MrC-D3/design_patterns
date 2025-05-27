#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <memory>


namespace CompositeNS
{

class Component
{
  public:
    ~Component() = default;
    // Default c'tors and operator= overloads, both copy and move.

    virtual void act() = 0;

    virtual void add(std::unique_ptr<Component>&& child);
};

} // namespace CompositeNS


#endif // COMPONENT_HPP