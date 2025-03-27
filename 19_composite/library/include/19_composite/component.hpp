#ifndef COMPONENT_HPP
#define COMPONENT_HPP


namespace CompositeNS
{
class Component
{
  public:
    ~Component() = default;

    virtual void act() = 0;
};

} // namespace CompositeNS


#endif // COMPONENT_HPP