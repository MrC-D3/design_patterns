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
    void behavior() override
    {
        std::cout << "I'm ComponentMock." << std::endl;
    }
};

class DecoratorConcreteTest : public ::testing::Test
{
  protected:
    DecoratorConcreteTest()
    {
        // Prefer c'tor/d'tor when you want to init const member variables and
        //  in case of sub-classing to be sure these operations are called.
        m_decorator = std::make_unique<DecoratorConcrete>( std::make_unique<ComponentMock>() );
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
    //std::unique_ptr<ComponentMock> m_component;
    std::unique_ptr<DecoratorConcrete> m_decorator;
};

TEST_F(DecoratorConcreteTest, test1)
{
    //EXPECT_CALL(*m_component, behavior).Times(AtLeast(1));
    auto original = std::cout.rdbuf();
    std::stringstream capture;
    std::cout.rdbuf(capture.rdbuf());

    m_decorator->behavior();

    EXPECT_NE( capture.str().find("ComponentMock"), std::string::npos );

    std::cout.rdbuf(original);
}