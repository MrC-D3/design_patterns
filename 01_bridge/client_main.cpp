#include "abstract_hierarchy.hpp"
#include "implementation_hierarchy.hpp"

int main()
{
    ColorInterface* color1 = new Color1();
    ShapeInterface* triangle = new Triangle(color1);

    triangle->draw();
}
