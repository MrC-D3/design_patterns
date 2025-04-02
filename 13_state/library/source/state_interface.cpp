#include "13_state/state_interface.hpp"
#include "13_state/context.hpp"


namespace State
{
    
StateInterface::StateInterface(const std::shared_ptr<Context>& context)
  : m_context(context)
{}


void StateInterface::set_context(const std::shared_ptr<Context>& context)
{
    m_context = context;
}

} // namespace State