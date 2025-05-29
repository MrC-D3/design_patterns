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
    // Default c'tors and operator= overloads, both copy and move.

    // Setters.
    void set_context(const std::shared_ptr<Context>& context);
    
    // Methods' names as in Context is not mandatory.
    virtual void do_something() = 0;
    virtual void do_something_else() = 0;

  protected:
    std::shared_ptr<Context> m_context;
};

} // namespace State


#endif // STATE_INTERFACE