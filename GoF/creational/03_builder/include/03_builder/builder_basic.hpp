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

/*
** Alternative solution: the Fluent Builder.
*/
class BuilderFluent
{
  public:
    // Default d'tor, c'tors and operator= overloads, both copy and move.

    BuilderFluent& Walls(const int walls_numer = 0);
    BuilderFluent& Windows(const int windows_numer = 0);
    BuilderFluent& Doors(const int doors_numer = 0);

    int walls_count;
    int windows_count;
    int doors_count;
};

class ProductFluent
{
  public:
    ProductFluent(const BuilderFluent& builder)
    {
        walls_count = builder.walls_count;
        windows_count = builder.windows_count;
        doors_count = builder.doors_count;
    }

    int walls_count;
    int windows_count;
    int doors_count;
};

} // namespace Builder

#endif
