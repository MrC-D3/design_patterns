// In case an Unit needs to interact with close other Units, it would iterate
//  over the whole list of Units in a space. To reduce the number of Units to 
//  iterate over, the Spatial Partition pattern divides a Space in sub-Spaces.

#ifndef SPATIAL_PARTITION_HPP
#define SPATIAL_PARTITION_HPP

#include <vector>
#include <cstdint>
#include <array>


namespace SpatialPartitionNS
{

class Space;

/*
** The class of objects that can be in a space.
*/
class Unit
{
  public:
    Unit(const uint16_t id, const uint16_t x, const uint16_t y, Space& space);
    // Default d'tor, c'tors and operator= overlaods, both copy and move.

    // To simplify, the interaction has radius 0, so only when (x,y)==(x,y).
    void interact(Space& space);

    // It'll call remove()+insert().
    void move(const uint16_t x, const uint16_t y, Space& space);

    // Data members.
    uint16_t m_id;
    // 2D space.
    uint16_t m_x;
    uint16_t m_y;
};

/*
** The class of a space.
*/
class Space
{
  public:
    // Default d'tor, c'tors and operator= overloads, both copy and move.

    void insert(Unit* unit);

    void remove(Unit* unit);

    void check_collisions(Unit* unit);

  private:
    std::vector<Unit*>& find_square(const uint16_t x, const uint16_t y);

    // Space 10x10 divided in 4 squares: 
    //  0 between (0,0) and (4,4)
    //  1 between (5,0) and (9,5)
    //  ...
    // Fixed number of squares for simplicity.
    //  Bad: if the Units in a square are too many, you lose efficiency.
    // Dynamic: if too many Units in 1 square, divide it in 4 sub-squares.
    //  Bad: adding/removing an Unit can be slow due to resizing the squares.
    // Containers can store only pointers or values, no references.
    std::vector<Unit*> m_square_0;
    std::vector<Unit*> m_square_1;
    std::vector<Unit*> m_square_2;
    std::vector<Unit*> m_square_3;
};

} // namespace SpatialPartitionNS


#endif // SPATIAL_PARTITION_HPP