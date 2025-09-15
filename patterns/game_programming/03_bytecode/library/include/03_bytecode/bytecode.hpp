#ifndef BYTECODE_HPP
#define BYTECODE_HPP

#include <variant>
#include <string>
#include <vector>
#include <iostream>


namespace BytecodeNS
{

// Encode the possible operations of an Non-Player Character (NPC).
enum class OperationCode
{
    MOVE,   // Move by N units
    WAIT,   // Wait for N time units
    SAY,    // Say a line (string)
    HALT    // Stop execution
};

// Move NPC's behavior outside the game's engine, so it can change at runtime.
struct Instruction
{
    OperationCode m_id;
    std::variant<int, std::string> m_operand;
};

// Be able to interpret the configuration data that contains the NPC's behavior.
class VirtualMachine
{
  public:
    // Default d'tor, c'tors and operator= overloads, both copy and move.
    void interpret(const std::vector<Instruction>& instructions);
};

} // namespace BytecodeNS


#endif // BYTECODE_HPP