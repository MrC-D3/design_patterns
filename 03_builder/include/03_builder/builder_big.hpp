#ifndef BUILDER_BIG_HPP
#define BUILDER_BIG_HPP

#include "03_builder/builder_basic.hpp"
#include "03_builder/product_house.hpp"


class BuilderBig : public BuilderBasic
{
  public:
    void build_foundations() override
    {
        m_house = new ProductHouse();
    }

    void build_walls() override
    {
        m_house->set_walls(8);
    }

    void build_doors() override
    {
        m_house->set_doors(2);
    }

    void build_windows() override
    {
        m_house->set_windows(16);
    }

    ProductHouse* get_house()
    {
        return m_house;
    }

  private:
    ProductHouse* m_house;
};

#endif
