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
    DecoratorConcreteTest()
    {
        // Prefer c'tor/d'tor when you want to init const member variables and
        //  in case of sub-classing to be sure these operations are called.
        m_decorator = new DecoratorConcrete(&m_component);
    }
    ~DecoratorConcreteTest()
    {
        delete m_decorator;
    }

    void SetUp() override
    {
        // Prefer SetUp/TearDown when calling virtual methods, throwing
        //  exceptions or using ASSERT_.
    }
    void TearDown() override
    {
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