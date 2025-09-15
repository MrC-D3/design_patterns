#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "07_composite/component.hpp"
#include "07_composite/composite.hpp"
#include "07_composite/leaf.hpp"


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
        auto mock_leaf = std::make_unique<MockLeaf>();
        m_mock_leaf = mock_leaf.get();

        m_composite.add( std::make_unique<Leaf>() );
        m_composite.add( std::move(mock_leaf) );
    }

    ~CompositeTestSuite()
    {}

    void SetUp()
    {}

    void TearDown()
    {}

    Composite m_composite;
    MockLeaf* m_mock_leaf;
};

// Tests.
TEST_F(CompositeTestSuite, CompositeTest)
{
    EXPECT_CALL(*m_mock_leaf, act).Times(AtLeast(1));

    testing::Mock::AllowLeak(m_mock_leaf);
    
    m_composite.act();
}