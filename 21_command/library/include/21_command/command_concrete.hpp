#ifndef COMMAND_CONCRETE_HPP
#define COMMAND_CONCRETE_HPP

#include "21_command/command_interface.hpp"
#include "21_command/receiver.hpp" // Forward declaration only for pointers.


namespace Command
{

class CommandConcrete : public CommandInterface
{
  public:
    explicit CommandConcrete(const Receiver& receiver);
    // Default d'tor, c'tors and operator= overloads, both copy and move.

    void executeA() override;
  private:
    Receiver m_receiver;
};

// Potentially other CommandConcrete-s, for each way the commands {A, B, ...} 
//  can be implemented.

} // namespace Command


#endif // COMMAND_CONCRETE_HPP