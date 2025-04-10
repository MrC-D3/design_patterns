#include "20_chain_of_responsibility/handler_interface.hpp"
#include "20_chain_of_responsibility/handler_concrete.hpp"


using namespace CoR;

int main()
{
    HandlerConcrete handler0(nullptr, 0);
    HandlerConcrete handler1(&handler0, 1);

    handler1.handleRequest(1);
    handler1.handleRequest(0);

    return 0;
}