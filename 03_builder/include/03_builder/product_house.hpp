#ifndef PRODUCT_HOUSE_HPP
#define PRODUCT_HOUSE_HPP

#include <iostream>


namespace Builder
{

class ProductHouse
{
  public:
    // Default d'tor, c'tors and operator= overloads, both copy and move.

    void set_walls(int walls)
    {
        m_walls = walls;
    }

    void set_windows(int windows)
    {
        m_windows = windows;
    }

    void set_doors(int doors)
    {
        m_doors = doors;
    }

    void show() const noexcept
    {
        std::cout << "I'm a house with " << m_walls << " walls, " << m_doors <<
          " doors, " << m_windows << " windows.\n";
    }

  private:
    int m_walls{0};
    int m_windows{0};
    int m_doors{0};
};

} // namespace Builder

#endif // PRODUCT_HOUSE_HPP
