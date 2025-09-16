#ifndef BUILDER_BIG_HPP
#define BUILDER_BIG_HPP

#include "01_builder/builder_basic.hpp"
#include "01_builder/product_house.hpp"

#include <memory>


namespace Builder
{

class BuilderBig final : public BuilderBasic
{
  public:
    ~BuilderBig() = default;
    // Default c'tors and operator= overloads, both copy and move.

    void build_foundations() override
    {
        // Any init or reset operations.
    }

    void build_walls() override
    {
        m_house.set_walls(8);
    }

    void build_doors() override
    {
        m_house.set_doors(2);
    }

    void build_windows() override
    {
        m_house.set_windows(16);
    }

    ProductHouse get_house()
    {
        return m_house;
    }

  private:
    ProductHouse m_house;
};

/*
** Alternative solution: the Fluent Builder.
*/
class BuilderFluentBig : public BuilderFluent
{
  public:
    // Default d'tor, c'tors and operator= overloads, both copy and move.

    BuilderFluent& Init() override
    {
        m_house.m_walls = m_house.m_windows = m_house.m_doors = 0;
        return *this;
    }

    BuilderFluent& Walls() override
    {
        m_house.m_walls = 8;
        return *this;
    }

    BuilderFluent& Windows() override
    {
        m_house.m_windows = 16;
        return *this;
    }

    BuilderFluent& Doors() override
    {
        m_house.m_doors = 2;
        return *this;
    }

    //operator ProductHouse() const 
    //{
    //    return m_house;
    //}
    ProductHouse get_house()
    {
        return m_house;
    }

  private:
    ProductHouse m_house;
};

} // namespace Builder


#endif // BUILDER_BIG_HPP
