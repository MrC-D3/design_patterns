#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "14_decorator/component_interface.hpp"
#include "14_decorator/decorator_concrete.hpp"
#include <memory>


using namespace Decorator;
using ::testing::AtLeast; 

class ComponentMock : public ComponentInterface
{
  public:
    // Default d'tor, c'tors and operator= overloads, both copy and move.

    MOCK_METHOD(void, behavior, (), (override));
};

class DecoratorConcreteTest : public ::testing::Test
{
  protected:
    DecoratorConcreteTest()
    {
        // Prefer c'tor/d'tor when you want to init const member variables and
        //  in case of sub-classing to be sure these operations are called.
        m_component = std::make_unique<ComponentMock>();
        m_component_ptr = m_component.get();
        m_decorator = std::make_unique<DecoratorConcrete>( 
          std::move(m_component)
        );
    }
    ~DecoratorConcreteTest()
    {}

    void SetUp() override
    {
        // Prefer SetUp/TearDown when calling virtual methods, throwing
        //  exceptions or using ASSERT_.
    }
    void TearDown() override
    {}

    // Class members.
    std::unique_ptr<ComponentMock> m_component;
    ComponentMock* m_component_ptr;
    std::unique_ptr<DecoratorConcrete> m_decorator;
};

TEST_F(DecoratorConcreteTest, test1)
{
    EXPECT_CALL(*m_component_ptr, behavior).Times(AtLeast(1));

    m_decorator->behavior();
}