#include "14_decorator/decorator_concrete.hpp"
#include "14_decorator/component_concrete.hpp"


using namespace Decorator;

int main()
{
    ComponentConcrete component;
    DecoratorConcrete decorator(&component);

    decorator.behavior();

    return 0;
}