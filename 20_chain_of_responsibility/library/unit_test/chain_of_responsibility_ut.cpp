#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "20_chain_of_responsibility/handler_interface.hpp"
#include "20_chain_of_responsibility/handler_concrete.hpp"


using namespace CoR;

class HandlerMock : public HandlerInterface
{
  public:
    HandlerMock(HandlerInterface* next, int request)
      : HandlerInterface(next)
    {
        m_request = request;
    }

    MOCK_METHOD( void, handleRequest, (int), (override) );
    MOCK_METHOD( bool, canHandle, (int), (override) );
};

class ChainOfResponsibilityTestFixture : public ::testing::Test
{
  protected:
    ChainOfResponsibilityTestFixture()
    {
        m_handler_1 = new HandlerMock(nullptr, 1);
        m_handler_0 = new HandlerConcrete(m_handler_1, 0);
    }

    ~ChainOfResponsibilityTestFixture()
    {
        delete m_handler_1;
        delete m_handler_0;
    }

    void SetUp()
    {}

    void TearDown()
    {}

    HandlerMock* m_handler_1;
    HandlerConcrete* m_handler_0;
};

TEST_F(ChainOfResponsibilityTestFixture, test_name)
{
    EXPECT_CALL(*m_handler_1, handleRequest).Times( ::testing::AtLeast(1) );

    m_handler_0->handleRequest(0);
    m_handler_0->handleRequest(1);
}