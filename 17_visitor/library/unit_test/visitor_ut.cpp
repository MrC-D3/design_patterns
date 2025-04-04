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
    MOCK_METHOD( void, visit, (const std::shared_ptr<ElementConcreteA>&), (override) );
    MOCK_METHOD( void, visit, (const std::shared_ptr<ElementConcreteB>&), (override) );
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
};

TEST_F(VisitorTestFixture, TestName)
{
    using ::testing::An;

    auto m_visitor = std::make_shared<VisitorMock>();
    EXPECT_CALL(*m_visitor, 
      visit( An<const std::shared_ptr<ElementConcreteA>&>() )
    ).Times(AtLeast(1));
    EXPECT_CALL(*m_visitor, 
      visit( An<const std::shared_ptr<ElementConcreteB>&>() )
    ).Times(AtLeast(1));

    // Range-based-for automatically calls begin().
    for(auto& i : m_object_structure.get_elements() )
    {
        i->access( m_visitor );
    }
}