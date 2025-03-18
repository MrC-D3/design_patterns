#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "14_decorator/component_interface.hpp"
#include "14_decorator/decorator_concrete.hpp"


using namespace Decorator;
using ::testing::AtLeast; 

class ComponentMock : public ComponentInterface
{
  public:
    MOCK_METHOD(void, behavior, (), (override));
};

class DecoratorConcreteTest : public ::testing::Test
{
  protected:
    DecoratorConcreteTest() = default;
    ~DecoratorConcreteTest() = default;

    void SetUp() override
    {
        m_decorator = new DecoratorConcrete(&m_component);
    }

    void TearDown() override
    {
        delete m_decorator;
    }

    // Class members.
    ComponentMock m_component;
    DecoratorConcrete* m_decorator;
};

TEST_F(DecoratorConcreteTest, test1)
{
    EXPECT_CALL(m_component, behavior).Times(AtLeast(1));

    m_decorator->behavior();
}