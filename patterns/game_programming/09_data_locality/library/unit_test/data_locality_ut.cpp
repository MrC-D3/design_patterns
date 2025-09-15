#include "09_data_locality/data_locality.hpp"

#include <gtest/gtest.h>


class DataLocalityFixture : public ::testing::Test
{
  protected:
    ~DataLocalityFixture()
    {}

    DataLocalityFixture()
    {}

    void SetUp()
    {}

    void TearDown()
    {}
};

TEST_F(DataLocalityFixture, test_name)
{
    using namespace DataLocalityNS;
    std::vector<Component1> components1{ Component1{0u}, Component1{1u}, Component1{2u} };

    for(Container i = 0u; i < components1.size(); i++)
    {
        components1[i].do_something();
    }
}