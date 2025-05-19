#include "20_chain_of_responsibility/handler_interface.hpp"


namespace CoR
{

HandlerInterface::HandlerInterface(HandlerInterface* next)
  : m_next(next)
{}

void HandlerInterface::handleRequest(int request)
{
    if( m_next != nullptr )
    {
        m_next->handleRequest(request);
    }
}

} // namespace CoR

