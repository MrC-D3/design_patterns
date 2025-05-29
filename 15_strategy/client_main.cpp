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

    // Template solution.
    {
        ContextT<StrategyConcrete> context{ 20 };
        context.apply_strategy();
    }

    return 0;
}