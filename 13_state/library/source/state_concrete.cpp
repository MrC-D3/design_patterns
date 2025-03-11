#include "13_state/state_concrete.hpp"

#include <iostream>


namespace State
{

void StateConcrete1::do_something()
{
    std::cout << "I'm State1. This won't change the state." << std::endl;
}

void StateConcrete1::do_something_else()
{
    std::cout << "I'm State1. This will change the state to State2." << 
      std::endl;
}


void StateConcrete2::do_something()
{
    std::cout << "I'm State2. This will change the state to State2." << std::endl;
}

void StateConcrete2::do_something_else()
{
    std::cout << "I'm State2. This won't change the state." << 
      std::endl;
}

} // namespace State