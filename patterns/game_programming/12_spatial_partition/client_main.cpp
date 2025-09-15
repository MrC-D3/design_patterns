#include "12_spatial_partition/spatial_partition.hpp"


int main()
{
    using namespace SpatialPartitionNS;
    Space space;
    Unit unit1{1, 0, 0, space};
    Unit unit2{2, 5, 5, space};
    
    unit1.interact(space);

    unit2.move(0, 0, space);
    unit2.interact(space);

    return 0;
}