#include "06_component/component.hpp"
#include <gtest/gtest.h>


using namespace ComponentNS;

class ComponentFixture : public ::testing::Test
{
  protected:
    ~ComponentFixture()
    {}

    ComponentFixture()
    {}

    void SetUp()
    {}

    void TearDown()
    {}
};

TEST_F(ComponentFixture, test_name)
{
    Component1 component1;
    Component2 component2;
    Container container(component1, component2);

    container.do_all();
}