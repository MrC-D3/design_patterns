#ifndef STATE_CONCRETE_HPP
#define STATE_CONCRETE_HPP

#include "13_state/state_interface.hpp"
#include <memory>


namespace State
{

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

} // namespace State


#endif // STATE_CONCRETE_HPP