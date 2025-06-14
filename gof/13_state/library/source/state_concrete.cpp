#include "13_state/state_concrete.hpp"
#include "13_state/context.hpp"
#include <iostream>


namespace State
{

/*
*  StateConcrete1 implementation.
*/
void StateConcrete1::do_something()
{
    std::cout << "I'm State1. This won't change the state.\n";
}

void StateConcrete1::do_something_else()
{
    std::cout << "I'm State1. This will change the state to State2.\n";

    // You can "delete this".
    m_context->set_state( std::make_unique<StateConcrete2>() );
}

/*
*  StateConcrete2 implementation.
*/
void StateConcrete2::do_something()
{
    std::cout << "I'm State2. This will change the state to State1.\n";

    m_context->set_state( std::make_unique<StateConcrete1>() );
}

void StateConcrete2::do_something_else()
{
    std::cout << "I'm State2. This won't change the state.\n";
}

} // namespace State