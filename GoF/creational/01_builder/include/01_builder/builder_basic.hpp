#ifndef BUILDER_BASIC_HPP
#define BUILDER_BASIC_HPP

#include "01_builder/product_house.hpp"


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

    virtual void build_foundations() {}
    virtual void build_walls() {}
    virtual void build_doors() {}
    virtual void build_windows() {}
};

/*
** Alternative solution: the Fluent Builder.
*/
class BuilderFluent
{
  public:
    // Default d'tor, c'tors and operator= overloads, both copy and move.

    // Alternative: return a pointer.
    virtual BuilderFluent& Init() { return *this;}
    virtual BuilderFluent& Walls() { return *this;}
    virtual BuilderFluent& Windows() { return *this;}
    virtual BuilderFluent& Doors() { return *this;}
};

} // namespace Builder

#endif
