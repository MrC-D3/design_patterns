#include "13_state/context.hpp"


namespace State
{

void Context::set_state(std::unique_ptr<StateInterface>&& state)
{
    m_state = std::move(state);
    m_state->set_context( shared_from_this() );
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