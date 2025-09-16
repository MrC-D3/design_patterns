// A.k.a. Sender.

#ifndef INVOKER_HPP
#define INVOKER_HPP

#include "01_command/command_interface.hpp"

#include <memory>
#include <functional>


namespace Command
{

/*
** Classic solution: with Command class hierarchy.
*/
class Invoker
{
  public:
    Invoker(std::unique_ptr<CommandInterface>&& command);
    // Default d'tor, c'tors and operator= overloads (only move).

    void call_command();

  private:
    std::unique_ptr<CommandInterface> m_command;
    // Potentially other Command pointers, for example for all the buttons of a 
    //  controller.
    // Or even a Composite Command (a.k.a. a Macro), that is a set of Commands
    //  managed as a unique Command.
};

/*
** Function-based solution.
*/
class InvokerF
{
  public:
    InvokerF(std::function<void(void)>& command);
    // Default d'tor, c'tors and operator= overloads (only move).

    void call_command();

  private:
    std::function<void(void)> m_command;
};

} // namespace Command


#endif // INVOKER_HPP