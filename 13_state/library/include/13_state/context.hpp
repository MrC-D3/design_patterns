#ifndef CONTEXT_HPP
#define CONTEXT_HPP

#include "13_state/state_interface.hpp"


namespace State
{

class Context
{
  public:
    Context(StateInterface* state = nullptr);

    // Both Context and StateConcrete can change state.
    void set_state(StateInterface* state);

    void do_something();
    void do_something_else();

  private:
    StateInterface* m_state;
};

} // namespace State


#endif // CONTEXT_HPP