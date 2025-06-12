#include "13_state/state_concrete.hpp"
#include "13_state/context.hpp"
#include <iostream>


namespace State
{

/*
** StateConcrete1 implementation.
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
** StateConcrete2 implementation.
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


/*
** StateConcreteCharacter1 implementation.
*/
std::unique_ptr<StateInterfaceCharacter> StateConcreteCharacter1::handle_input
  (char input)
{
    switch(input)
    {
        case '1':
            // Still in State1, don't change state.
            return nullptr;
        case '2':
            return std::make_unique<StateConcreteCharacter2>();
    }

    // Input not recognized, don't change state.
    return nullptr;
}

/*
** StateConcreteCharacter2 implementation.
*/
std::unique_ptr<StateInterfaceCharacter> StateConcreteCharacter2::handle_input
  (char input)
{
    switch(input)
    {
        case '1':
            return std::make_unique<StateConcreteCharacter1>();
        case '2':
            // Still in State2, don't change state.
            return nullptr;
    }

    // Input not recognized, don't change state.
    return nullptr;
}

} // namespace State