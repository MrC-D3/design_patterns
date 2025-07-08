#include "13_state/context.hpp"
#include "13_state/state_concrete.hpp"


using namespace State;

int main()
{
    // Example 01: classic.
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
    }

    // Example 02: game programming.
    {
        ContextCharacter character(std::make_unique<StateConcreteCharacter1>());

        character.handle_input('1');
        character.handle_input('2');
        
        character.handle_input('2');
        character.handle_input('1');
    }

    // Example 03: Boost::MSM.
    {
        StateMachineT state_machine;

        // Start the state machine (initial state: State1).
        state_machine.start();

        std::cout << "Switching to State2...\n";
        state_machine.process_event(S1toS2());

        std::cout << "Switching to State1...\n";
        state_machine.process_event(S1toS2());
    }
    
    return 0;
}
