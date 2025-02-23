#ifndef DIRECTOR_TOTAL_HPP
#define DIRECTOR_TOTAL_HPP

#include <string>

#include "03_builder/builder_basic.hpp"
#include "03_builder/product_house.hpp"


class DirectorHouse
{
  public:
    DirectorHouse(BuilderBasic* builder)
      : m_builder(builder)
    {}

    void build_house()
    {
        m_builder->build_foundations();
        m_builder->build_walls();
        m_builder->build_doors();
        m_builder->build_windows();
    }

  private:
    BuilderBasic* m_builder;
};

#endif
