#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "21_command/command_interface.hpp"
#include "21_command/invoker.hpp"


using namespace Command;

class MockCommand : public CommandInterface
{
  public:
    MOCK_METHOD(void, execute, ());
};

class CommandTestFixture : public ::testing::Test
{
  protected:
    CommandTestFixture()
    {}
    
    ~CommandTestFixture()
    {}

    void SetUp()
    {}

    void TearDown()
    {}

    MockCommand m_command;
    Invoker* m_invoker= new Invoker(&m_command);
};

TEST_F(CommandTestFixture, call_command)
{
    EXPECT_CALL(m_command, execute).Times(::testing::AtLeast(1));

    m_invoker->call_command();
}