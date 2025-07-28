#include "15_strategy/strategy_concrete.hpp"

#include <iostream>


namespace Strategy
{

void StrategyConcrete::do_something(const std::int64_t data)
{
    std::cout << "I'm the StrategyConcrete. I'll do in my way using: " << 
        data << ".\n";
}

} // namespace Strategy
