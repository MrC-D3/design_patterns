#ifndef COMPOSITE_HPP
#define COMPOSITE_HPP

#include "19_composite/component.hpp"
#include <list>


namespace CompositeNS
{

class Composite final : public Component
{
  public:
    ~Composite() = default;
    Composite() = default;

    Composite(const Composite& origin) = default;
    Composite& operator=(const Composite& origin) = default;

    Composite(Composite&& origin) = default;
    Composite& operator=(Composite&& origin) = default;

    void act() override;

    void add(std::unique_ptr<Component>&& child) override;

  private:
    std::list<std::unique_ptr<Component>> m_children;
};

} // namespace CompositeNS


#endif // COMPOSITE_HPP
