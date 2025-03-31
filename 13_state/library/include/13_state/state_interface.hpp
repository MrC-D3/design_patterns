#ifndef STATE_INTERFACE
#define STATE_INTERFACE

#include <memory>


namespace State
{

class Context;

class StateInterface
{
  public:
    virtual ~StateInterface() = default;
    StateInterface(std::unique_ptr<Context>&& context);
    // Copy c'tor can't exist, since unique_ptr<T> can't be copied.
    StateInterface(const StateInterface& origin) = delete;
    // Move c'tor.
    StateInterface(StateInterface&& origin);

    // Assign operations.
    StateInterface& operator=(const StateInterface& origin) = delete;
    StateInterface& operator=(StateInterface&& origin);
    
    // Methods' names as in Context is not mandatory.
    virtual void do_something() = 0;
    virtual void do_something_else() = 0;

  protected:
    std::unique_ptr<Context> m_context;
};

} // namespace State


#endif // STATE_INTERFACE