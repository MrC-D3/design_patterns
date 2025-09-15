#include "03_bytecode/bytecode.hpp"


int main()
{
    using namespace BytecodeNS;

    VirtualMachine vm;
    const std::vector<Instruction>& instructions{
        {OperationCode::SAY, "Hello!"},
        {OperationCode::MOVE, 10},
    };

    vm.interpret(instructions);

    return 0;
}