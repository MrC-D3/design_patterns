#include <gtest/gtest.h>
#include <gmock/gmock.h>


class DecoratorConcreteTest : public ::testing::Test
{
  protected:
    DecoratorConcreteTest() = default;
    ~DecoratorConcreteTest() = default; // override?

    void SetUp() override
    {}

    void TearDown() override
    {}

    // Class members.
    
};

TEST_F(DecoratorConcreteTest, test1)
{

}