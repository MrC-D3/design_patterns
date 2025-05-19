#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "20_chain_of_responsibility/handler_interface.hpp"
#include "20_chain_of_responsibility/handler_concrete.hpp"


using namespace CoR;

class HandlerMock : public HandlerInterface
{
  public:
    HandlerMock(std::unique_ptr<HandlerInterface>&& next, const int request)
      : HandlerInterface(std::move(next))
    {
        m_request = request;
    }

    MOCK_METHOD( void, handleRequest, (const int), (override) );
    MOCK_METHOD( bool, canHandle, (const int), (override) );
};

class ChainOfResponsibilityTestFixture : public ::testing::Test
{
  protected:
    ChainOfResponsibilityTestFixture()
    {
        m_handler_1 = std::make_unique<HandlerMock>(nullptr, 1);
        m_handler_0 = std::make_unique<HandlerConcrete>(std::move(m_handler_1), 0);
    }

    ~ChainOfResponsibilityTestFixture()
    {}

    void SetUp()
    {}

    void TearDown()
    {}

    std::unique_ptr<HandlerMock> m_handler_1;
    std::unique_ptr<HandlerConcrete> m_handler_0;
};

TEST_F(ChainOfResponsibilityTestFixture, test_name)
{
    //EXPECT_CALL(*m_handler_1, handleRequest).Times( ::testing::AtLeast(1) );

    m_handler_0->handleRequest(0);
    m_handler_0->handleRequest(1);
}