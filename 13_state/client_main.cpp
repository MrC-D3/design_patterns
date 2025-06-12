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
    
    return 0;
}
