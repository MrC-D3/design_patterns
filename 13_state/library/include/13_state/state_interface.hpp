#ifndef STATE_INTERFACE
#define STATE_INTERFACE


namespace State
{

class Context;

class StateInterface
{
  public:
    virtual ~StateInterface() = default;
    StateInterface(Context* context);
    
    // Methods names as in Context is not mandatory.
    virtual void do_something() = 0;
    virtual void do_something_else() = 0;

  protected:
    Context* m_context;
};

} // namespace State


#endif // STATE_INTERFACE