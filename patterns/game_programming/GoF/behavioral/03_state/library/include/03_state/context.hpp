#ifndef CONTEXT_HPP
#define CONTEXT_HPP

#include "03_state/state_interface.hpp"
#include <memory>


namespace State
{

/*
** Example 01: classic.
*/
class Context : public std::enable_shared_from_this<Context>
{
  public:
    // Default d'tor, c'tors and operator= overloads, both copy and move.

    // Both Context and StateConcrete can change state.
    void set_state(std::unique_ptr<StateInterface>&& state);

    void do_something();
    void do_something_else();

  private:
    std::unique_ptr<StateInterface> m_state;
};

/*
** Example 02: game programming.
*/
class ContextCharacter
{
  public:
    ContextCharacter(std::unique_ptr<StateInterfaceCharacter>&& state);
    // Default d'tor, c'tors and operator= overloads, both copy and move.

    void handle_input(char input);

  private:
    // Here the simplest example: a Finite State Machine (FSM).
    // In Concurrent State Machine (CSM), you have multiple states (e.g. dress
    //  and weapon), indipendent from each other and each input can affect both.
    // In Hierarchical State Machine (HSM), you group common behaviors in a base
    //  state and then you specify it: you can model it with inheritance or with
    //  a stack of states.
    // In Pushdown Automata, you use a stack of states for keeping history, so
    //  when the life-cycle of a state ends (e.g. stop firing) you know which 
    //  state to go back to.
    std::unique_ptr<StateInterfaceCharacter> m_state;
};

} // namespace State


#endif // CONTEXT_HPP