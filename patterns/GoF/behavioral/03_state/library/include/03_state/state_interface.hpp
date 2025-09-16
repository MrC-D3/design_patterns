#ifndef STATE_INTERFACE
#define STATE_INTERFACE

#include <memory>
#include <iostream>
#include <boost/msm/front/state_machine_def.hpp>
#include <boost/msm/front/functor_row.hpp>  // ← Header specifico per Row


namespace State
{

/*
** Example 01: classic.
*/
class Context;
class StateInterface
{
  public:
    virtual ~StateInterface() = default;
    // Default c'tors and operator= overloads, both copy and move.

    // Setters.
    void set_context(const std::shared_ptr<Context>& context);
    
    // Methods' names as in Context is not mandatory.
    virtual void do_something() = 0;
    virtual void do_something_else() = 0;

  protected:
    std::shared_ptr<Context> m_context;
};

/*
** Example 02: game programming.
*/
class ContextCharacter;
class StateInterfaceCharacter
{
  public:
    ~StateInterfaceCharacter() = default;

    virtual std::unique_ptr<StateInterfaceCharacter> handle_input(char input) 
      = 0;
};

/*
** Example 03: Boost::MSM.
*/
namespace msm = boost::msm;
namespace mpl = boost::mpl;

// Events
struct S1toS2 {};
struct S2toS1 {};

// State Machine Frontend Definition
struct StateMachineDefinition : public msm::front::state_machine_def<StateMachineDefinition>
{
    // States
    struct State1 : public msm::front::state<> 
    {
        template <class Event, class FSM>
        void on_entry(Event const&, FSM&)
        {
            std::cout << "State1: on_entry\n";
        }

        template <class Event, class FSM>
        void on_exit(Event const&, FSM&)
        {
           std::cout << "State1: on_exit\n";
        }
    };

    struct State2 : public msm::front::state<>
    {
        template <class Event, class FSM>
        void on_entry(Event const&, FSM&)
        {
          std::cout << "State2: on_entry\n";
        }

        template <class Event, class FSM>
        void on_exit(Event const&, FSM&)
        {
            std::cout << "State2: on_exit\n";
        }
    };

    // Initial State: mandatory typedef.
    typedef State1 initial_state;

    // Action.
    struct NotifyS1toS2
    {
        template <class Event, class FSM, class SourceState, class TargetState>
        void operator()(Event const&, FSM&, SourceState&, TargetState&)
        {
            std::cout << "Action: notify S1 to S2 switch!\n";
        }
    };

    // Transition Table
    struct TransitionTable : mpl::vector<
        // Row:          Start   Event   Next    Action        Guard
        msm::front::Row< State1, S1toS2, State2, NotifyS1toS2, msm::front::none >,
        msm::front::Row< State2, S2toS1, State1, msm::front::none,    msm::front::none >
    > {};

    // No-Transition Handler: when an event in a state doesn't change the state.
    //  E.g.: S1toS2 when already in S2.
    template <class Event, class FSM>
    void no_transition(Event const& e, FSM&, int state)
    {
        std::cout << "No transition for event in state " << state << std::endl;
    }
};

} // namespace State


#endif // STATE_INTERFACE