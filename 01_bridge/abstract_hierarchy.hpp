#ifndef ABSTRACT_HIERARCHY_HPP
#define ABSTRACT_HIERARCHY_HPP

#include "implementation_hierarchy.hpp"

#include <memory>


class ShapeInterface
{
  public:
    ShapeInterface(std::unique_ptr<ColorInterface> color)
      : m_color(std::move(color))
    {}

    virtual ~ShapeInterface() noexcept = default; 

    virtual void draw() = 0;

  protected:
    std::unique_ptr<ColorInterface> m_color;
};


class Triangle final : public ShapeInterface
{
  public:
    Triangle(std::unique_ptr<ColorInterface> color)
      : ShapeInterface(std::move(color))
    {}

    void draw() override
    {
        m_color->draw();
    }
};

#endif // ABSTRACT_HIERARCHY_HPP
