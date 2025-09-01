#include "03_decorator/decorator_concrete.hpp"
#include "03_decorator/component_concrete.hpp"
#include <memory>
#include <string>


using namespace Decorator;

int main()
{
    // Classic Solution with inheritance.
    {
      DecoratorConcrete decorator{ std::make_unique<ComponentConcrete>() };

      decorator.behavior();
    }

    // Alternative Solution 01 with CRTP.
    {
        DecoratorAdvanced<ComponentConcrete> decorator('A');

        decorator.behavior();
    }

    // Alternative Solution 02 with function decorator.
    {
        auto to_decorate =
          [](const std::string& input){
            return std::string{"Hello " + input};
        };

        DecoratorFunction<std::string, const std::string&> decorated{to_decorate};
        auto to_return = decorated("world");

        std::cout << to_return << std::endl;
    }

    return 0;
}
