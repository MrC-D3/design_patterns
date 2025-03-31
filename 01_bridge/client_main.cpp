#include "abstract_hierarchy.hpp"
#include "implementation_hierarchy.hpp"

#include <memory>


int main()
{
    std::unique_ptr<ColorInterface> color1 = std::make_unique<Color1>();
    std::unique_ptr<ShapeInterface> triangle = 
      std::make_unique<Triangle>(std::move(color1));

    triangle->draw();
}
