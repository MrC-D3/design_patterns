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
    virtual ~Invoker() = default;
    Invoker(std::unique_ptr<CommandInterface>&& command);

    Invoker(const Invoker& origin) = delete;
    Invoker& operator=(const Invoker& origin) = delete;

    Invoker(Invoker&& origin) = default;
    Invoker& operator=(Invoker&& origin) = default;

    void call_command();

  private:
    std::unique_ptr<CommandInterface> m_command;
};

} // namespace Command

#endif // INVOKER_HPP