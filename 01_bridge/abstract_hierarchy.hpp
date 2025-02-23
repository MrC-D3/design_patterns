#ifndef ABSTRACT_HIERARCHY_HPP
#define ABSTRACT_HIERARCHY_HPP

#include "implementation_hierarchy.hpp"

class ShapeInterface
{
  public:
    ShapeInterface(ColorInterface* color)
      : m_color(color)
    {}

    virtual void draw() = 0;

  protected:
    ColorInterface* m_color;
};

class Triangle : public ShapeInterface
{
  public:
    Triangle(ColorInterface* color)
      : ShapeInterface(color)
    {}

    void draw() override
    {
        m_color->draw();
    }
};

#endif
