#include "20_chain_of_responsibility/handler_concrete.hpp"
#include <iostream>


namespace CoR
{

HandlerConcrete::HandlerConcrete(HandlerInterface* next, int request)
  : HandlerInterface(next)
{
    m_request = request;
}

void HandlerConcrete::handleRequest(int request) 
{
    if( canHandle(request) )
    {
        std::cout << "I'm a HandlerConcrete. I'll handle request: " << m_request
          << std::endl;
    }
    else if(m_next != nullptr)
    {
        // You use override, but you respect the Open/Close Principle, because
        //  you aren't changing the parent definition, you are extending it.
        HandlerInterface::handleRequest(request);
    }
    
}

bool HandlerConcrete::canHandle(int request)
{
    return (request == m_request);
}

} // namespace CoR