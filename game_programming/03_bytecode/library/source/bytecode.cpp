#include "03_bytecode/bytecode.hpp"


namespace BytecodeNS
{

void VirtualMachine::interpret(const std::vector<Instruction>& instructions)
{
    int position = 0;

    for(const auto& instruction : instructions)
    {
        switch (instruction.m_id)
        {
            case OperationCode::MOVE:
            // Each case doesn't create its own scope, so - if you init a
            //  variable - wrap the case with brackets.
            {
                // It won't compile if you try to use directly m_operand.
                int delta = std::get<int>(instruction.m_operand);
                position += delta;
                std::cout << "NPC moved to position " << position << "\n";
                break;
            }
            case OperationCode::WAIT: 
            {
                int time = std::get<int>(instruction.m_operand);
                std::cout << "NPC waits for " << time << " seconds\n";
                break;
            }
            case OperationCode::SAY: 
            {
                std::string text = std::get<std::string>(instruction.m_operand);
                std::cout << "NPC says: \"" << text << "\"\n";
                break;
            }
            case OperationCode::HALT:
                std::cout << "Execution halted.\n";
                return;
        }
    }
}

} // namespace BytecodeNS