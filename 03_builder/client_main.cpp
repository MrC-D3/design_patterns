#include "03_builder/director_house.hpp"
#include "03_builder/builder_small.hpp"
#include "03_builder/builder_big.hpp"
#include "03_builder/product_house.hpp"

#include <memory>


int main()
{
    using namespace Builder;
    
    // CASE 01: small house.
    {
        std::unique_ptr<BuilderSmall> builder_small = std::make_unique<BuilderSmall>();
        DirectorHouse director(std::move(builder_small));
        director.build_house();

        std::unique_ptr<ProductHouse> house = builder_small->get_house();
        house->show();

        // Memory freed by the d'tor-s.
    }

    // CASE 02: big house.
    {
        std::unique_ptr<BuilderBig> builder_big = std::make_unique<BuilderBig>();
        DirectorHouse director(std::move(builder_big));
        director.build_house();

        std::unique_ptr<ProductHouse> house = builder_big->get_house();
        house->show();
    }

    return 0;
}
