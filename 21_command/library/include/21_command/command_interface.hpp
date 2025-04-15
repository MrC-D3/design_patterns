#ifndef COMMAND_INTERFACE_HPP
#define COMMAND_INTERFACE_HPP


namespace Command
{

class CommandInterface
{
  public:
    virtual ~CommandInterface() = default;
    CommandInterface() = default;

    CommandInterface(const CommandInterface& origin) = default;
    CommandInterface& operator=(const CommandInterface& origin) = default;

    CommandInterface(CommandInterface&& origin) = default;
    CommandInterface& operator=(CommandInterface&& origin) = default;

    virtual void execute() = 0;
};

} // namespace Command

#endif // COMMAND_INTERFACE_HPP