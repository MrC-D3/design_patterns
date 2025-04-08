#ifndef LEAF_HPP
#define LEAF_HPP

#include "19_composite/component.hpp"


namespace CompositeNS
{
  
class Leaf final : public Component
{
  public:
    ~Leaf() = default;
    Leaf() = default;

    Leaf(const Leaf& origin) = default;
    Leaf& operator=(const Leaf& origin) = default;

    Leaf(Leaf&& origin) = default;
    Leaf& operator=(Leaf&& origin) = default;

    void act() override;
};

} // namespace CompositeNS


#endif // LEAF_HPP