#ifndef LEAF_HPP
#define LEAF_HPP

#include "19_composite/component.hpp"


namespace CompositeNS
{
class Leaf : public Component
{
  public:
    void act() override;
};

} // namespace CompositeNS


#endif // LEAF_HPP