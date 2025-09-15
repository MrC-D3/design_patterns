#include "12_spatial_partition/spatial_partition.hpp"

#include <gtest/gtest.h>


class SpatialPartitionFixture : public ::testing::Test
{
  protected:
    ~SpatialPartitionFixture()
    {}

    SpatialPartitionFixture()
    {}

    void SetUp()
    {}

    void TearDown()
    {}
};

TEST_F(SpatialPartitionFixture, test_name)
{
    using namespace SpatialPartitionNS;
    Space space;
    Unit unit1{1, 0, 0, space};
    Unit unit2{2, 1, 1, space};
    
    unit1.interact(space);

    unit2.move(0, 0, space);
    unit2.interact(space);
}