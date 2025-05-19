#include "20_chain_of_responsibility/handler_concrete.hpp"
#include <iostream>


namespace CoR
{

HandlerConcrete::HandlerConcrete(std::unique_ptr<HandlerInterface>&& next, 
  const std::int32_t request)
  : HandlerInterface{std::move(next)}
  // m_request declared in the base class, so can't be initialized here. 
{
    m_request = request;
}

void HandlerConcrete::handleRequest(const std::int32_t request) 
{
    if( canHandle(request) )
    {
        std::cout << "I'm a HandlerConcrete. I'll handle request: " << m_request
          << ".\n";
    }
    else if(m_next)
    {
        // You use override, but you respect the Open/Close Principle, because
        //  you aren't changing the parent definition, you are extending it.
        HandlerInterface::handleRequest(request);
    }
    
}

bool HandlerConcrete::canHandle(const std::int32_t request)
{
    return (request == m_request);
}

} // namespace CoR