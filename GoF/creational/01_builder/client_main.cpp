#include "01_builder/director_house.hpp"
#include "01_builder/builder_small.hpp"
#include "01_builder/builder_big.hpp"
#include "01_builder/product_house.hpp"

#include <memory>


int main()
{
    using namespace Builder;
    
    // CASE 01: small house.
    {
        auto builder_small = std::make_shared<BuilderSmall>();

        // Curly brackets for c'tor to:
        //  - avoid most-vexing-parse, i.d. ambiguity between function & object;
        //  - avoid narrowing-conversion, i.d. int x{1.5} fails;
        //  - be coherent with aggregate objects initialization.
        DirectorHouse director{builder_small};

        director.build_house();

        auto house = builder_small->get_house();
        house.show();

        // Memory freed by the d'tor-s.
    }

    // CASE 02: big house.
    {
        auto builder_big = std::make_shared<BuilderBig>();
        DirectorHouse director{builder_big};
        director.build_house();

        auto house = builder_big->get_house();
        house.show();
    }

    /*
    ** Alternative solution: the Fluent Builder.
    */
    {
        auto builder_big = std::make_shared<BuilderFluentBig>();

        // This line can be delegated to a Director.
        builder_big->Init().Walls().Windows().Doors();

        ProductHouse house = builder_big->get_house();

        house.show();
    }

    return 0;
}
