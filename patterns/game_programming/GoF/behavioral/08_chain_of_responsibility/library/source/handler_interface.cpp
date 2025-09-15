#include "08_chain_of_responsibility/handler_interface.hpp"


namespace CoR
{

HandlerInterface::HandlerInterface(
  std::unique_ptr<HandlerInterface>&& next,
  const std::int32_t request)
: m_next{ std::move(next) },
  m_request{ request }
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

