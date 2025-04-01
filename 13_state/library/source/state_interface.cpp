#include "13_state/state_interface.hpp"
#include "13_state/context.hpp"


namespace State
{
    
StateInterface::StateInterface(std::unique_ptr<Context>&& context)
  : m_context(std::move(context))
{}

StateInterface::StateInterface(StateInterface&& origin)
  : m_context(std::move(origin.m_context))
{
    // Moving an object to itself is safe, so no need to check this!=origin.
}

StateInterface& StateInterface::operator=(StateInterface&& origin)
{
    // Data members populated using operator=.
    m_context = std::move(origin.m_context);
    // Returning the calling instance itself.
    return *this;
}

void StateInterface::set_context(std::shared_ptr<Context> context)
{
    m_context = context;
}

} // namespace State