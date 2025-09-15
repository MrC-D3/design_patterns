// Same problem can be solved using Functional Type too (pro: no many classes).
#include "02_strategy/context.hpp"
#include "02_strategy/strategy_concrete.hpp"


using namespace Strategy;

int main()
{
    /*
    ** Classic solution.
    */
    {
        Context context{ std::make_unique<StrategyConcrete>(), 10 };
        context.apply_strategy();
    }

    /*
    ** Function-based solution.
    */
    {
        std::function<void(const int)> f = [](const int data){
          std::cout << "I'm the strategy lambda. I'll do in my way using: "
          << data << ".\n";
        };
        ContextF context{
          // 1st parameter.
          f,
          // 2nd parameter.
          10
        };
        context.apply_strategy();
    }

    /*
    ** Template solution.
    */
    {
        ContextT<StrategyConcrete> context{ 20 };
        context.apply_strategy();
    }

    return 0;
}