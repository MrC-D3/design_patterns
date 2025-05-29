#ifndef ABSTRACT_HIERARCHY_HPP
#define ABSTRACT_HIERARCHY_HPP

#include "implementation_hierarchy.hpp"

#include <memory>


class ShapeInterface
{
  public:
    virtual ~ShapeInterface() noexcept = default; 

    ShapeInterface(std::unique_ptr<ColorInterface>&& color)
      : m_color{std::move(color)}
    {}

    // No copy.
    ShapeInterface(const ShapeInterface& origin) = delete;
    ShapeInterface& operator=(const ShapeInterface& origin) = delete;

    // Default move c'tor and operator= overload.

    virtual void draw() = 0;

  protected:
    // It could be also "const ColorInterface&" and allow copy operation.
    std::unique_ptr<ColorInterface> m_color;
};

class Triangle final : public ShapeInterface
{
  public:
    Triangle(std::unique_ptr<ColorInterface>&& color)
      : ShapeInterface{std::move(color)}
    {}

    // Default d'tor, c'tor and operator= overload for the move.

    // No copy.
    Triangle(const Triangle& origin) = delete;
    Triangle& operator=(const Triangle& origin) = delete;

    void draw() override
    {
        std::cout << "I'm a Triangle.\n";
        m_color->draw();
    }
};


#endif // ABSTRACT_HIERARCHY_HPP
