// The same problem can be solved using Functional Type (pro: no many classes)
//  or with Template Programming (con: you know which strategy at compile time).
#include "15_strategy/context.hpp"
#include "15_strategy/strategy_concrete.hpp"


using namespace Strategy;

int main()
{
    Context context( std::make_unique<StrategyConcrete>(), 10);

    context.apply_strategy();

    return 0;
}