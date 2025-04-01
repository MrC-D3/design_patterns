#ifndef CONTEXT_HPP
#define CONTEXT_HPP

#include "13_state/state_interface.hpp"
#include <memory>


namespace State
{

class Context : public std::enable_shared_from_this<Context>
{
  public:
    Context(std::unique_ptr<StateInterface>&& state = nullptr);
    Context(const Context& origin) = delete;
    Context(Context&& origin);

    // Both Context and StateConcrete can change state.
    void set_state(std::unique_ptr<StateInterface>&& state);
    void set_next_state(std::unique_ptr<StateInterface>&& state);

    void do_something();
    void do_something_else();

  private:
    std::unique_ptr<StateInterface> m_state;
    // Need m_next_state when using smart pointers or the calling StateConcreteX
    //  would delete itself when change state.
    std::unique_ptr<StateInterface> m_next_state;

    void update_state();
};

} // namespace State


#endif // CONTEXT_HPP