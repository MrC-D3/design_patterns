#include "02_strategy/context.hpp"
#include "02_strategy/strategy_concrete.hpp"
#include "02_strategy/strategy_interface.hpp"
#include <memory>
#include <iostream>

#include <gtest/gtest.h>
#include <gmock/gmock.h>


using namespace Strategy;

using ::testing::AtLeast;

class StrategyMock : public StrategyInterface
{
  public:
    MOCK_METHOD( void, do_something, (const std::int64_t), (override) );
};

class StrategyFixture : public ::testing::Test
{
  protected:
    StrategyFixture()
    {
        m_strategy = std::make_unique<StrategyMock>();
        m_strategy_ptr = m_strategy.get();
        m_context = std::make_unique<Context>( std::move(m_strategy) );
    }

    ~StrategyFixture()
    {}

    void SetUp()
    {}
    void TearDown()
    {}

    std::unique_ptr<StrategyMock> m_strategy;
    StrategyMock* m_strategy_ptr;
    std::unique_ptr<Context> m_context;;
};

TEST_F(StrategyFixture, TestName)
{
    EXPECT_CALL(*m_strategy_ptr, do_something).Times(AtLeast(1));

    m_context->apply_strategy();
}