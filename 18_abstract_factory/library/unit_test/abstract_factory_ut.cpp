#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "18_abstract_factory/abstract_factory.hpp"
#include "18_abstract_factory/element_interface.hpp"


using namesapce AbstractFactoryNS;
using ::testing::AtLeast;

// Mocks.


// Fixtures.
class AbstractFactoryFixture : public ::testing::Test
{
  protected:
    AbstractFactoryFixture()
    {}

    ~AbstractFactoryFixture()
    {}

    void SetUp()
    {}

    void TearDown()
    {}
};

// Tests.
TEST_F(AbstractFactoryFixture, Test1)
{}