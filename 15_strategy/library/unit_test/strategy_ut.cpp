#include "15_strategy/context.hpp"
#include "15_strategy/strategy_concrete.hpp"
#include "15_strategy/strategy_interface.hpp"
#include <memory>
#include <iostream>

#include <gtest/gtest.h>
#include <gmock/gmock.h>


using namespace Strategy;

using ::testing::AtLeast;

class StrategyMock : public StrategyInterface
{
  public:
    void do_something(const std::int64_t&) override
    {
        std::cout << "I'm StrategyMock." << std::endl;
    }
};

class StrategyFixture : public ::testing::Test
{
  protected:
    StrategyFixture()
    {}
    ~StrategyFixture()
    {}

    void SetUp()
    {}
    void TearDown()
    {}

    Context m_context{ std::make_unique<StrategyMock>(), 10 };
};

TEST_F(StrategyFixture, TestName)
{
    //EXPECT_CALL(*m_strategy, do_something).Times(AtLeast(1));
    auto original = std::cout.rdbuf();
    std::stringstream capture;
    std::cout.rdbuf(capture.rdbuf());
    
    m_context.apply_strategy();

    EXPECT_NE( capture.str().find("I'm StrategyMock."), std::string::npos );

    std::cout.rdbuf(original);
}