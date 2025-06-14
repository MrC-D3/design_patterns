#ifndef BUILDER_SMALL_HPP
#define BUILDER_SMALL_HPP

#include "03_builder/builder_basic.hpp"
#include "03_builder/product_house.hpp"

#include <memory>


namespace Builder
{

class BuilderSmall final : public BuilderBasic
{
  public:
    ~BuilderSmall() = default;
    // Default c'tors and operator= overloads, both copy and move.
    
    void build_foundations() override
    {
        // Any init or reset operations.
    }

    void build_walls() override
    {
        m_house.set_walls(4);
    }

    void build_doors() override
    {
        m_house.set_doors(1);
    }

    void build_windows() override
    {
        m_house.set_windows(4);
    }

    ProductHouse get_house()
    {
        return m_house;
    }

  private:
    // In general, each Builder can work with a Product unrelated to the 
    //  Products of other Builders; that's why you have it here and not in
    //  BuilderBasic and why you can avoid poninters.
    ProductHouse m_house;
};

} // namespace Builder


#endif // BUILDER_SMALL_HPP
