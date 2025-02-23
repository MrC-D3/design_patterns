#ifndef FLYWEIGHT_UNSHARED_HPP
#define FLYWEIGHT_UNSHARED_HPP

#include <iostream>
#include <string>

#include "05_flyweight/flyweight_shared.hpp"


class FlyweightUnshared
{
  public:
    FlyweightUnshared(uint64_t position, FlyweightShared* shared_data);

    void draw(std::string& canvas);

  private:
    uint64_t m_position = 0;
    FlyweightShared* m_shared_data = nullptr;
};


#endif
