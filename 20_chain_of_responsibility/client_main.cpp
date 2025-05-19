#include "20_chain_of_responsibility/handler_interface.hpp"
#include "20_chain_of_responsibility/handler_concrete.hpp"

#include <memory>


using namespace CoR;

int main()
{
    auto handler0 = std::make_unique<HandlerConcrete>(nullptr, 0);
    auto handler1 = std::make_unique<HandlerConcrete>(std::move(handler0), 1);

    handler1->handleRequest(1);
    handler1->handleRequest(0);

    return 0;
}