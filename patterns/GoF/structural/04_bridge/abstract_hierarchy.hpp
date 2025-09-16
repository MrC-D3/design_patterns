#ifndef ABSTRACT_HIERARCHY_HPP
#define ABSTRACT_HIERARCHY_HPP

#include "implementation_hierarchy.hpp"

#include <memory>


/*
** Classic use-case: avoid Cartesian product between 2 class hierarchies.
*/
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

/*
** Alternative use-case: implement the PIMPL idiom.
*/
class AbstractClass
{
  public:
    class ImplementationClass;
    // Default d'tor, c'tors and operator= overloads, both copy and move.
    AbstractClass(const int data);

    void do_something();
    
  private:
    // Init of data members based on declaration order, so you get a warning if
    //  the init list in the c'tor has a different order.
    ImplementationClass* m_pimpl_bridge;
    int m_data;
};


#endif // ABSTRACT_HIERARCHY_HPP
