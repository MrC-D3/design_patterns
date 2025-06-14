#ifndef BUILDER_BASIC_HPP
#define BUILDER_BASIC_HPP

#include "03_builder/product_house.hpp"


// The rule is that the root class of the Builder Hierarchy shouldn't have pure
//  virtual methods, so each child Builder can override only the methods it
//  wants; so, define a default behavior.

namespace Builder
{

class BuilderBasic
{
  public:
    virtual ~BuilderBasic() = default;

    // Default c'tors and operator= overloads, both copy and move.

    virtual void build_foundations() {};
    virtual void build_walls() {};
    virtual void build_doors() {};
    virtual void build_windows() {};
};

} // namespace Builder

#endif
