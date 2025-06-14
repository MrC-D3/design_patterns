#ifndef IMPLEMENTATION_HIERARCHY_HPP
#define IMPLEMENTATION_HIERARCHY_HPP

#include <iostream>


class ColorInterface
{
  public:
    virtual ~ColorInterface() noexcept = default;
    // Default c'tors and operator= overloads (both copy and move).

    virtual void draw() const = 0;
};

class Blue final : public ColorInterface
{
  public:
    // Default d'tor, c'tors and operator= overloads (both copy and move).

    // Keyword "override" must be at the end.
    void draw() const override
    {
        std::cout << "This is a shape drawn in Blue.\n";
    }
};


#endif // IMPLEMENTATION_HIERARCHY_HPP
