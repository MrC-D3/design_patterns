#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "16_template_method/abstract_class.hpp"
#include "16_template_method/concrete_class.hpp"


// Using-s.
using namespace TemplateMethod;
using ::testing::AtLeast;

// Mock-s.
class MockClass : public AbstractClass
{
  protected:
    MOCK_METHOD( void, primitive_operation1, (), (override) );

    void hook() override
    {
        std::cout << "I'm the MockClass. I'm doing the hook.\n";
    }

    MOCK_METHOD( void, primitive_operation2, (), (override) );
};

// Fixture.
class TemplateMethodFixture : public ::testing::Test
{
  protected:
    TemplateMethodFixture()
    {
        oldBuffer = std::cout.rdbuf();
        std::cout.rdbuf(buffer.rdbuf());
    }

    ~TemplateMethodFixture()
    {
        std::cout.rdbuf(oldBuffer);
    }

    void SetUp()
    {}

    void TearDown()
    {}

    MockClass m_object;
    std::stringstream buffer;
    std::streambuf* oldBuffer{nullptr};
};

// Test-s.
TEST_F(TemplateMethodFixture, test_name)
{
    // EXPECT_CALL() can be called only on public methods.

    m_object.template_method();

    // Buffer contains also some GMock's output, so strings comparison fail.
    EXPECT_NE(buffer.str().find("I'm the MockClass. I'm doing the hook."), 
      std::string::npos);
}
