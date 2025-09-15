#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "03_abstract_factory/abstract_factory.hpp"
#include "03_abstract_factory/element_interface.hpp"
#include "03_abstract_factory/element_concrete.hpp"


using namespace AbstractFactoryNS;
using ::testing::AtLeast;

// Mocks.
class MockFactory : public AbstractFactory
{
  public:
    std::unique_ptr<ElementInterfaceA> factoryElementA() override
    {
        return std::make_unique<ElementConcreteA1>();
    }
};

// Fixtures.
class AbstractFactoryFixture : public ::testing::Test
{
  protected:
    AbstractFactoryFixture()
    {
        m_oldBuffer = std::cout.rdbuf();
        std::cout.rdbuf(m_buffer.rdbuf());
    }

    ~AbstractFactoryFixture()
    {
        std::cout.rdbuf(m_oldBuffer);
    }

    void SetUp()
    {}

    void TearDown()
    {}

    MockFactory m_factory;
    std::streambuf* m_oldBuffer = nullptr;
    std::stringstream m_buffer;
};

// Tests.
TEST_F(AbstractFactoryFixture, Test1)
{
    auto elementA = m_factory.factoryElementA();
        
    elementA->doA();

    EXPECT_NE(m_buffer.str().find("I'm ElementConcreteA1."), std::string::npos);
}