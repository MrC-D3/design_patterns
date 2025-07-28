#include "14_decorator/decorator_concrete.hpp"
#include "14_decorator/component_concrete.hpp"
#include <memory>


using namespace Decorator;

int main()
{
    // Solution with inheritance.
    {
      DecoratorConcrete decorator{ std::make_unique<ComponentConcrete>() };

      decorator.behavior();
    }

    // Solution with inheritance and template.
    {
        DecoratorAdvanced<ComponentConcrete> decorator('A');

        decorator.behavior();
    }

    return 0;
}
