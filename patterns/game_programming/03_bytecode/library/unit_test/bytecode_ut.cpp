#include "03_bytecode/bytecode.hpp"

#include "gtest/gtest.h"
#include "gmock/gmock.h"


using namespace BytecodeNS;

class BytecodeFixture : public ::testing::Test
{
  protected:
    ~BytecodeFixture()
    {}

    BytecodeFixture()
    {}

    void SuiteUp()
    {}

    void TearDown()
    {}
};

TEST_F(BytecodeFixture, interpret_test)
{
    VirtualMachine vm;
    const std::vector<Instruction>& instructions{
        {OperationCode::SAY, "Hello!"}
    };

    vm.interpret(instructions);

    //ASSERT_EQ(position, 1.0);
}