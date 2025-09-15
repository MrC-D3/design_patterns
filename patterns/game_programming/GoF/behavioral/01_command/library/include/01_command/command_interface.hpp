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

    // It's better to let one class store only one Command, but potentially you
    //  can define other virtual methods like executeB etc.
};

} // namespace Command


#endif // COMMAND_INTERFACE_HPP