#include "08_chain_of_responsibility/handler_interface.hpp"
#include "08_chain_of_responsibility/handler_concrete.hpp"

#include <memory>


using namespace CoR;

int main()
{
    // Classic solution.
    {
        auto handler0 = std::make_unique<HandlerConcrete>(nullptr, 0);
        auto handler1 = std::make_unique<HandlerConcrete>(std::move(handler0), 1);

        handler1->handleRequest(1);
        handler1->handleRequest(0);
    }

    // Alternative solution with C++11 std::function.
    {
        HandlerAlternative handler;
        handler(0);
        handler(1);
    }

    return 0;
}