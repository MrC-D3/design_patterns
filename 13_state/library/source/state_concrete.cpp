#include "13_state/state_concrete.hpp"
#include "13_state/context.hpp"
#include <iostream>


namespace State
{

StateConcrete1::StateConcrete1(std::unique_ptr<Context>&& context)
  : StateInterface(std::move(context))
{}

StateConcrete1& StateConcrete1::operator=(StateConcrete1&& origin)
{
    m_context = std::move( origin.m_context );
    return *this;
}

void StateConcrete1::do_something()
{
    std::cout << "I'm State1. This won't change the state." << std::endl;
}

void StateConcrete1::do_something_else()
{
    std::cout << "I'm State1. This will change the state to State2." << 
      std::endl;

    m_context->set_next_state( std::make_unique<StateConcrete2>() );
}


StateConcrete2::StateConcrete2(std::unique_ptr<Context>&& context)
  : StateInterface(std::move(context))
{}

StateConcrete2& StateConcrete2::operator=(StateConcrete2&& origin)
{
    m_context = std::move( origin.m_context );
    return *this;
}

void StateConcrete2::do_something()
{
    std::cout << "I'm State2. This will change the state to State2." << std::endl;

    m_context->set_next_state( std::make_unique<StateConcrete1>() );
}

void StateConcrete2::do_something_else()
{
    std::cout << "I'm State2. This won't change the state." << 
      std::endl;
}

} // namespace State