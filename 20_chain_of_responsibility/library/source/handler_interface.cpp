#include "20_chain_of_responsibility/handler_interface.hpp"


namespace CoR
{

HandlerInterface::HandlerInterface(std::unique_ptr<HandlerInterface>&& next)
  : m_next(std::move(next))
{}

// Defaul behavior: pass the request.
void HandlerInterface::handleRequest(const std::int32_t request)
{
    if( m_next )
    {
        m_next->handleRequest(request);
    }
}

} // namespace CoR

