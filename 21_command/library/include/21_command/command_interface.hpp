#ifndef COMMAND_INTERFACE_HPP
#define COMMAND_INTERFACE_HPP


namespace Command
{

class CommandInterface
{
  public:
    virtual ~CommandInterface() = default;
    // Default c'tors and operator= overloads, both copy and mov.

    virtual void executeA() = 0;

    // Potentially executeB and other possible commands the Invoker can need.
};

} // namespace Command


#endif // COMMAND_INTERFACE_HPP