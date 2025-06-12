#include "13_state/context.hpp"


namespace State
{

/*
** Example 01 implementation.
*/
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

/*
** Example 02 implementation.
*/
ContextCharacter::ContextCharacter(
  std::unique_ptr<StateInterfaceCharacter>&& state)
: m_state(std::move(state))
{}

void ContextCharacter::handle_input(char input)
{
    auto new_state = m_state->handle_input(input);
    if(new_state)
    {
        // m_state.exit(this) to do something like stopping a sound.
        m_state = std::move(new_state);
        // m_state.enter(this) to do something like starting a sound.
    }
}

} // namespace State