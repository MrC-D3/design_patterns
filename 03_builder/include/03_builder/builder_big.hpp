#ifndef BUILDER_BIG_HPP
#define BUILDER_BIG_HPP

#include "03_builder/builder_basic.hpp"
#include "03_builder/product_house.hpp"

#include <memory>


namespace Builder
{

class BuilderBig final : public BuilderBasic
{
  public:
    ~BuilderBig() = default;


    void build_foundations() override
    {
        m_house = std::make_unique<ProductHouse>();
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


    std::unique_ptr<ProductHouse> get_house()
    {
        return std::move(m_house);
    }

  private:
    std::unique_ptr<ProductHouse> m_house;
};

}

#endif // BUILDER_BIG_HPP
