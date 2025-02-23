#ifndef IMPLEMENTATION_HIERARCHY_HPP
#define IMPLEMENTATION_HIERARCHY_HPP

#include <iostream>


class ColorInterface
{
  public:
    virtual void draw() = 0;
};

class Color1 : public ColorInterface
{
  public:
    void draw() override
    {
        std::cout << "This is a shape drawn in Color1." << std::endl;
    }
};

#endif
