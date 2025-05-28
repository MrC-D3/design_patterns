#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "21_command/command_interface.hpp"
#include "21_command/invoker.hpp"


using namespace Command;

class MockCommand : public CommandInterface
{
  public:
    MOCK_METHOD(void, executeA, ());
};

class CommandTestFixture : public ::testing::Test
{
  protected:
    CommandTestFixture()
    {
        auto command = std::make_unique<MockCommand>();
        m_raw_command = command.get();
        m_invoker = std::make_unique<Invoker>(std::move(command));
    }
    
    ~CommandTestFixture()
    {}

    void SetUp()
    {}

    void TearDown()
    {}

    MockCommand* m_raw_command;
    // Writing here m_invoker(&m_command) doesn't work because not enough order
    //  context for the compiler: use c'tor initializer list.
    std::unique_ptr<Invoker> m_invoker;
};

TEST_F(CommandTestFixture, call_command)
{
    EXPECT_CALL(*m_raw_command, executeA).Times(::testing::AtLeast(1));

    m_invoker->call_command();
}