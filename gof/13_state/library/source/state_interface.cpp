#include "13_state/state_interface.hpp"
#include "13_state/context.hpp"


namespace State
{

/*
** Example 01 implementation. 
*/
void StateInterface::set_context(const std::shared_ptr<Context>& context)
{
    m_context = context;
}

/*
** Example 02 doesn't need implementation.
*/

} // namespace State