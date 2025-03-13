#include "13_state/state_interface.hpp"
#include "13_state/context.hpp"


namespace State
{
    
StateInterface::StateInterface(Context* context)
  : m_context(context)
{
    
}

} // namespace State