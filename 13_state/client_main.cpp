#include "13_state/context.hpp"
#include "13_state/state_concrete.hpp"


using namespace State;

int main()
{
    // Init.
    auto context = std::make_shared<Context>();
    context->set_state( std::make_unique<StateConcrete1>() );

    // Call.
    context->do_something();
    context->do_something();

    context->do_something_else();
    context->do_something_else();
    context->do_something_else();

    context->do_something();
    context->do_something();
    
    return 0;
}
