#include "13_state/context.hpp"
#include "13_state/state_concrete.hpp"


using namespace State;

int main()
{
    // Init.
    Context context;
    StateConcrete1 state1(&context);

    // Call.
    context.set_state(&state1);
    context.do_something();
    context.do_something();

    context.do_something_else();
    context.do_something_else();
    context.do_something_else();

    context.do_something();
    context.do_something();
    
    return 0;
}