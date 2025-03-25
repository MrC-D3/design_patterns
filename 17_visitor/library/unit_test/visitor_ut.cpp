#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "17_visitor/visitor_interface.hpp"
#include "17_visitor/element_concrete.hpp"
#include "17_visitor/object_structure.hpp"


using namespace Visitor;
using ::testing::AtLeast;

class VisitorMock : public VisitorInterface
{
  public:
    MOCK_METHOD( void, visitA, (ElementConcreteA*), (override) );
    MOCK_METHOD( void, visitB, (ElementConcreteB*), (override) );
};

class VisitorTestFixture : public ::testing::Test
{
  protected:
    VisitorTestFixture()
    {}

    ~VisitorTestFixture()
    {}

    void SetUp()
    {}

    void TearDown()
    {}

    ObjectStructure m_object_structure;
    VisitorMock m_visitor;
};

TEST_F(VisitorTestFixture, TestName)
{
    EXPECT_CALL(m_visitor, visitA).Times(AtLeast(1));
    EXPECT_CALL(m_visitor, visitB).Times(AtLeast(1));

    for(auto i : m_object_structure.get_elements())
    {
        i->access(&m_visitor);
    }
}