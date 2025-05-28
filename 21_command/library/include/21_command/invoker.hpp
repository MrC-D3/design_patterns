#ifndef INVOKER_HPP
#define INVOKER_HPP

#include "21_command/command_interface.hpp"

#include <memory>


namespace Command
{

// A.k.a. Sender.
class Invoker
{
  public:
    Invoker(std::unique_ptr<CommandInterface>&& command);
    // Default d'tor, c'tors and operator= overloads (only move).

    void call_command();

  private:
    std::unique_ptr<CommandInterface> m_command;
};

} // namespace Command


#endif // INVOKER_HPP