#ifndef INVOKER_HPP
#define INVOKER_HPP

#include "21_command/command_interface.hpp"


namespace Command
{

// A.k.a. Sender.
class Invoker
{
  public:
    virtual ~Invoker() = default;
    Invoker(CommandInterface* command);

    Invoker(const Invoker& origin) = default;
    Invoker& operator=(const Invoker& origin) = default;

    Invoker(Invoker&& origin) = default;
    Invoker& operator=(Invoker&& origin) = default;

    void call_command();

  private:
    CommandInterface* m_command;
};

} // namespace Command

#endif // INVOKER_HPP