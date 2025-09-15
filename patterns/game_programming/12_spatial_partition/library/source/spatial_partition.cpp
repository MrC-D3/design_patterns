#include "12_spatial_partition/spatial_partition.hpp"

#include <iostream>


namespace SpatialPartitionNS
{

/*
** The Unit class implementation.
*/
Unit::Unit(const uint16_t id, const uint16_t x, const uint16_t y, Space& space)
: m_id{id}, m_x{x}, m_y{y}
{
    space.insert(this);
}

void Unit::interact(Space& space)
{
    space.check_collisions(this);
}

void Unit::move(const uint16_t x, const uint16_t y, Space& space)
{
    // Optimization: remove it only if it changes subspace.
    space.remove(this);

    m_x = x;
    m_y = y;

    space.insert(this);
}

/*
** The Space class implementation.
*/
std::vector<Unit*>& Space::find_subspace(const uint16_t x, const uint16_t y)
{
    // OR  int cellX = (int)(x / Grid::CELL_SIZE);

    if (x < 5)
    {
        // Sub-space 0 or 2.
        if (y < 5)
        {
            return m_subspace_0;
        }
        else
        {
            return m_subspace_2;     
        }
    }
    else
    {
        // Sub-space 1 or 3.
        if (y < 5)
        {
            return m_subspace_1;
        }
        else
        {
            return m_subspace_3;
        }
    }
}

void Space::insert(Unit* unit)
{
    auto& subspace = find_subspace(unit->m_x, unit->m_y);
    subspace.push_back(unit);
}

void Space::remove(Unit* unit)
{
    auto& subspace = find_subspace(unit->m_x, unit->m_y);
    for(auto it = subspace.begin(); it!= subspace.end(); it++)
    {
        if (*it == unit)
        {
            subspace.erase(it);
            break;
        }
    }
}

void Space::check_collisions(Unit* unit)
{
    auto& subspace = find_subspace(unit->m_x, unit->m_y);

    for(auto& other : subspace)
    {
        if(other == unit)
        {
            continue;
        }

        if ((other->m_x == unit->m_x) && (other->m_y == unit->m_y))
        {
            std::cout << "Collision between " << unit->m_id << " and " << 
              other->m_id << ".\n";
        }
    }
}


} // namespace SpatialPartitionNS
