#ifndef CONTEXT_HPP
#define CONTEXT_HPP

#include "13_state/state_interface.hpp"


namespace State
{

class Context
{
  public:
    Context(std::unique_ptr<StateInterface>&& state = nullptr);
    Context(const Context& origin) = delete;
    Context(Context&& origin);

    // Both Context and StateConcrete can change state.
    void set_state(std::unique_ptr<StateInterface>&& state);

    void do_something();
    void do_something_else();

  private:
    std::unique_ptr<StateInterface> m_state;
};

} // namespace State


#endif // CONTEXT_HPP