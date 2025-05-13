#include "22_interpreter/abstract_expression.hpp"
#include "22_interpreter/terminal_expression.hpp"
#include "22_interpreter/nonterminal_expression.hpp"

#include <gtest/gtest.h>
#include <gmock/gmock.h>


using namespace Interpreter;

// Mock-s.
class MockExpression : public AbstractExpression
{
  public:
    MOCK_METHOD(bool, interpret, (), (override));
};

class InterpreterFixture : public ::testing::Test
{
  protected:
    ~InterpreterFixture()
    {}

    InterpreterFixture()
    {}

    void SetUp()
    {}

    void TearDown()
    {}
};

TEST_F(InterpreterFixture, test_name)
{
    MockExpression expression1;
    TerminalExpression expression2(true);
    NonterminalExpression0 sentence(&expression1, &expression2);

    EXPECT_CALL(expression1, interpret).Times( ::testing::AtLeast(1) );

    auto result = sentence.interpret();
}
