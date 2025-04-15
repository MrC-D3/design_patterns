#ifndef COMMAND_CONCRETE_HPP
#define COMMAND_CONCRETE_HPP

#include "21_command/command_interface.hpp"
#include "21_command/receiver.hpp" // Forward declaration only for pointers.


namespace Command
{

class CommandConcrete : public CommandInterface
{
  public:
    ~CommandConcrete() = default;
    CommandConcrete(const Receiver& receiver);

    CommandConcrete(const CommandConcrete& origin) = default;
    CommandConcrete& operator=(const CommandConcrete& origin) = default;

    CommandConcrete(CommandConcrete&& origin) = default;
    CommandConcrete& operator=(CommandConcrete&& origin) = default;

    void execute() override;

  private:
    Receiver m_receiver;
};

} // namespace Command

#endif // COMMAND_CONCRETE_HPP