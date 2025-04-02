#include "14_decorator/decorator_concrete.hpp"
#include "14_decorator/component_concrete.hpp"
#include <memory>


using namespace Decorator;

int main()
{
    ComponentConcrete component;
    auto decorator = std::make_unique<DecoratorConcrete>( 
      std::make_unique<ComponentConcrete>() );

    decorator->behavior();

    return 0;
}