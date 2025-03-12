#include "13_state/state_concrete.hpp"

#include <iostream>


namespace State
{

StateConcrete1::StateConcrete1(Context* context)
  : StateInterface(context)
{
}

void StateConcrete1::do_something()
{
    std::cout << "I'm State1. This won't change the state." << std::endl;
}

void StateConcrete1::do_something_else()
{
    std::cout << "I'm State1. This will change the state to State2." << 
      std::endl;

    m_context->set_state(new StateConcrete2(m_context));
}


StateConcrete2::StateConcrete2(Context* context)
  : StateInterface(context)
{
}

void StateConcrete2::do_something()
{
    std::cout << "I'm State2. This will change the state to State2." << std::endl;

    m_context->set_state(new StateConcrete1(m_context));
}

void StateConcrete2::do_something_else()
{
    std::cout << "I'm State2. This won't change the state." << 
      std::endl;
}

} // namespace State