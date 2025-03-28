#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "19_composite/component.hpp"
#include "19_composite/composite.hpp"
#include "19_composite/leaf.hpp"


using namespace CompositeNS;
using ::testing::AtLeast;

// Mocks.
class MockLeaf : public Component
{
  public:
    MOCK_METHOD(void, act, (), (override));
};

// Fixture.
class CompositeTestSuite : public ::testing::Test
{
  protected:
    CompositeTestSuite()
    {
        m_composite.add(&m_leaf);
        m_composite.add(&m_mock_leaf);
    }

    ~CompositeTestSuite()
    {}

    void SetUp()
    {}

    void TearDown()
    {}

    Composite m_composite;
    Leaf m_leaf;
    MockLeaf m_mock_leaf;

};

// Tests.
TEST_F(CompositeTestSuite, CompositeTest)
{
    EXPECT_CALL(m_mock_leaf, act).Times(AtLeast(1));
    
    m_composite.act();
}