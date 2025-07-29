#ifndef COMMAND_CONCRETE_HPP
#define COMMAND_CONCRETE_HPP

#include "21_command/command_interface.hpp"
#include "21_command/receiver.hpp" // Forward declaration only for pointers.


namespace Command
{

class CommandConcrete : public CommandInterface
{
  public:
    // You can set the Receiver here or as parameter of executeA().
    // In case of undo support (i.e. when the Command makes sense in a specific
    //  time point), it's better to fix it here.
    explicit CommandConcrete(const Receiver& receiver);
    // Default d'tor, c'tors and operator= overloads, both copy and move.

    void executeA() override;
  private:
    // In a game development context, the receiver can be the playing character.
    Receiver m_receiver;
};

// Potentially other CommandConcrete-s, for example all the Commands that you
//  can map on a controller's button.

} // namespace Command


#endif // COMMAND_CONCRETE_HPP