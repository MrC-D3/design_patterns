#ifndef BUILDER_SMALL_HPP
#define BUILDER_SMALL_HPP

#include "03_builder/builder_basic.hpp"
#include "03_builder/product_house.hpp"


class BuilderSmall : public BuilderBasic
{
  public:
    void build_foundations() override
    {
        m_house = new ProductHouse();
    }

    void build_walls() override
    {
        m_house->set_walls(4);
    }

    void build_doors() override
    {
        m_house->set_doors(1);
    }

    void build_windows() override
    {
        m_house->set_windows(4);
    }

    ProductHouse* get_house()
    {
        return m_house;
    }

  private:
    // Only one Product class hiearchy, so you could move it to BuilderBasic.
    // Kept here to make the example more adherent to the design pattern.
    ProductHouse* m_house;
};

#endif
