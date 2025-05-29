#include "13_state/state_interface.hpp"
#include "13_state/context.hpp"


namespace State
{

void StateInterface::set_context(const std::shared_ptr<Context>& context)
{
    m_context = context;
}

} // namespace State