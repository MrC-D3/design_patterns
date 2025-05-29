#ifndef LEAF_HPP
#define LEAF_HPP

#include "19_composite/component.hpp"


namespace CompositeNS
{
  
class Leaf final : public Component
{
  public:
    // Default d'tor, c'tors and operator= overloads, both copy and move.

    void act() override;
};

} // namespace CompositeNS


#endif // LEAF_HPP