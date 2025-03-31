#include "13_state/context.hpp"


namespace State
{

Context::Context(std::unique_ptr<StateInterface>&& state)
  : m_state( std::move(state) )
{}

Context::Context(Context&& origin)
  : m_state( std::move(origin.m_state) )
{}

void Context::set_state(std::unique_ptr<StateInterface>&& state)
{
    m_state = std::move(state);
}

void Context::do_something()
{
    m_state->do_something();
}

void Context::do_something_else()
{
    m_state->do_something_else();
}

} // namespace State