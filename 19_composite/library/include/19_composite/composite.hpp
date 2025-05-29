#ifndef COMPOSITE_HPP
#define COMPOSITE_HPP

#include "19_composite/component.hpp"
#include <list>


namespace CompositeNS
{

class Composite final : public Component
{
  public:
    // Default d'tor, c'tors and operator= overloads, both copy and move.

    void act() override;

    void add(std::unique_ptr<Component>&& child) override;

  private:
    std::list<std::unique_ptr<Component>> m_children;
};

} // namespace CompositeNS


#endif // COMPOSITE_HPP
