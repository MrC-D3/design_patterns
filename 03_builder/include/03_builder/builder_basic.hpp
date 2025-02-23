#ifndef BUILDER_BASIC_HPP
#define BUILDER_BASIC_HPP

#include "03_builder/product_house.hpp"


// The rule is that the root class of the Builder Hierarchy shouldn't have pure
//  virtual methods, so each children Builders che override only the methods it
//  wants; so, define a default behavior.

class BuilderBasic
{
  public:
    virtual void build_foundations() {};

    virtual void build_walls() {};

    virtual void build_doors() {};

    virtual void build_windows() {};
};

#endif
