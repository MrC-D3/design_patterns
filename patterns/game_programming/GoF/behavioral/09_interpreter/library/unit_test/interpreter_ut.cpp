#include "09_interpreter/abstract_expression.hpp"
#include "09_interpreter/terminal_expression.hpp"
#include "09_interpreter/nonterminal_expression.hpp"
#include "09_interpreter/context.hpp"

#include <gtest/gtest.h>
#include <gmock/gmock.h>


using namespace Interpreter;

// Mock-s.
class MockExpression : public AbstractExpression
{
  public:
    MOCK_METHOD(bool, interpret, (const Context&), (const, override));
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
    auto expression1 = std::make_shared<MockExpression>();
    auto expression2 = std::make_shared<TerminalExpression>("X");
    NonterminalExpression0 sentence(
      expression1,
      expression2
    );
    Context context;
    context.assign(expression2, true);

    EXPECT_CALL(*expression1, interpret).Times( ::testing::AtLeast(1) );

    auto result = sentence.interpret(context);
}
