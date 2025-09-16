#ifndef STATE_CONCRETE_HPP
#define STATE_CONCRETE_HPP

#include "03_state/state_interface.hpp"
#include <memory>
#include <boost/msm/back/state_machine.hpp>


namespace State
{

/*
** Example 01: classic.
*/
class StateConcrete1 : public StateInterface
{
  public:
    // Default d'tor, c'tors and operator= overloads, both copy and move.

    void do_something() override;
    void do_something_else() override;
};

class StateConcrete2 : public StateInterface
{
  public:
    // Default d'tor, c'tors and operator= overloads, both copy and move.

    void do_something() override;
    void do_something_else() override;
};

/*
** Example 02: game programming.
*/
class StateConcreteCharacter1 : public StateInterfaceCharacter
{
  public:
    // Default d'tor, c'tors and operator= overloads, both copy and move.

    std::unique_ptr<StateInterfaceCharacter> handle_input(char input) override;
};

class StateConcreteCharacter2 : public StateInterfaceCharacter
{
  public:
    // Default d'tor, c'tors and operator= overloads, both copy and move.

    std::unique_ptr<StateInterfaceCharacter> handle_input(char input) override;
};

/*
** Example 03: Boost.MSM.
*/
// State Machine Backend Definition
typedef msm::back::state_machine<StateMachineDefinition> StateMachineT;

} // namespace State


#endif // STATE_CONCRETE_HPP