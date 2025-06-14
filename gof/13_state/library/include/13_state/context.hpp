#ifndef CONTEXT_HPP
#define CONTEXT_HPP

#include "13_state/state_interface.hpp"
#include <memory>


namespace State
{

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

} // namespace State


#endif // CONTEXT_HPP