#include "15_strategy/context.hpp"
#include "15_strategy/strategy_concrete.hpp"
#include "15_strategy/strategy_interface.hpp"

#include <gtest/gtest.h>
#include <gmock/gmock.h>


using namespace Strategy;

using ::testing::AtLeast;

class StrategyMock : public StrategyInterface
{
  public:
    MOCK_METHOD( void, do_something, (std::int64_t), (override) );
};

class StrategyFixture : public ::testing::Test
{
  protected:
    StrategyFixture()
    {
        m_strategy = new StrategyMock();
        m_context = new Context(m_strategy);
    }

    ~StrategyFixture()
    {
        delete m_strategy;
        delete m_context;
    }

    void SetUp()
    {}
    void TearDown()
    {}

    Context* m_context;
    StrategyMock* m_strategy;
};

TEST_F(StrategyFixture, TestName)
{
    EXPECT_CALL(*m_strategy, do_something).Times(AtLeast(1));
    
    m_context->apply_strategy();
}