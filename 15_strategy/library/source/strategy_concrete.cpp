#include "15_strategy/strategy_concrete.hpp"

#include <iostream>


namespace Strategy
{

void StrategyConcrete::do_something(std::int64_t data)
{
    std::cout << "I'm the StrategyConcrete. I'll do in my way using: " << 
        data << std::endl;
}

} // namespace Strategy
