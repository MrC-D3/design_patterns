#include "03_builder/director_house.hpp"
#include "03_builder/builder_small.hpp"
#include "03_builder/builder_big.hpp"
#include "03_builder/product_house.hpp"

int main()
{
    // CASE 01: small house.
    {
        BuilderSmall* builder_small = new BuilderSmall();
        DirectorHouse director(builder_small);
        director.build_house();
        ProductHouse* house = builder_small->get_house();

        house->show();
        delete house;
    }

    // CASE 02: big house.
    {
        BuilderBig* builder_big = new BuilderBig();
        DirectorHouse director(builder_big);
        director.build_house();
        ProductHouse* house = builder_big->get_house();

        house->show();
        delete house;
    }

    return 0;
}
