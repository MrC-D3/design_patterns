#include "05_type_object/type_object.hpp"

#include <gtest/gtest.h>


using namespace TypeObjectNS;

class TypeObjectFixture : public ::testing::Test
{
  protected:
    ~TypeObjectFixture()
    {}

    TypeObjectFixture()
    {}

    void SetUp()
    {}

    void TearDown()
    {}
};

TEST_F(TypeObjectFixture, test_name)
{
    TypeObject type1{1};
    auto typed1 = type1.typedObjectFactory();
}