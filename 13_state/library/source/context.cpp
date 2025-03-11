#include "13_state/context.hpp"


namespace State
{

Context::Context(StateInterface* state)
  : m_state(state)
{

}

void Context::set_state(StateInterface* state)
{
    m_state = state;
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