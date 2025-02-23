#ifndef PRODUCT_HOUSE_HPP
#define PRODUCT_HOUSE_HPP

#include <iostream>


class ProductHouse
{
  public:
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

    void show()
    {
      std::cout << "I'm a house with " << m_walls << " walls, " << m_doors <<
        " doors, " << m_windows << " windows." << std::endl;
    }

  private:
    int m_walls;
    int m_windows;
    int m_doors;
};

#endif
