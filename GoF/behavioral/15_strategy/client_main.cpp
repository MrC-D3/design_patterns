// Same problem can be solved using Functional Type (pro: no many classes) too.
#include "15_strategy/context.hpp"
#include "15_strategy/strategy_concrete.hpp"


using namespace Strategy;

int main()
{
    // Classic solution.
    {
        Context context{ std::make_unique<StrategyConcrete>(), 10 };
        context.apply_strategy();
    }

    // Function-based solution.
    {
        Context context{
          // 1st parameter.
          [](const std::int64_t data){
            std::cout << "I'm the strategy lambda. I'll do in my way using: "
            << data << ".\n";
          },
          // 2nd parameter.
          10
         };
        context.apply_strategy();
    }

    // Template solution.
    {
        ContextT<StrategyConcrete> context{ 20 };
        context.apply_strategy();
    }

    return 0;
}