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
    
    update_state();
}

void Context::do_something_else()
{
    m_state->do_something_else();

    update_state();
}

void Context::set_next_state(std::unique_ptr<StateInterface>&& state)
{
    m_next_state = std::move(state);
}

void Context::update_state()
{
    if(m_next_state)
    {
        m_state = std::move(m_next_state); // Makes m_next_state nullptr.
        m_state->set_context( shared_from_this() );
    }
}

} // namespace State