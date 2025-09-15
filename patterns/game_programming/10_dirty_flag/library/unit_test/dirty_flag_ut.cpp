#include "10_dirty_flag/dirty_flag.hpp"

#include <gtest/gtest.h>


class DirtyFlagFixture : public ::testing::Test
{
  protected:
    ~DirtyFlagFixture()
    {}

    DirtyFlagFixture()
    {}

    void SetUp()
    {}

    void TearDown()
    {}
};

TEST_F(DirtyFlagFixture, test_name)
{
    using namespace DirtyFlagNS;
    ParentClass parent{1};
    EXPECT_EQ( parent.m_child.get_data(), 2);
    EXPECT_EQ( parent.m_child.get_data(), 2);

    parent.set_data(10);
    EXPECT_EQ( parent.m_child.get_data(), 20);
    EXPECT_EQ( parent.m_child.get_data(), 20);
}