#ifndef COMPOSITE_HPP
#define COMPOSITE_HPP

#include "19_composite/component.hpp"
#include <list>


namespace CompositeNS
{

class Composite : public Component
{
  public:
    void act() override;

    void add(Component* child) override;

  private:
    std::list<Component*> m_children;
};

} // namespace CompositeNS


#endif // COMPOSITE_HPP
