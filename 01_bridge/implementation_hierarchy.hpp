#ifndef IMPLEMENTATION_HIERARCHY_HPP
#define IMPLEMENTATION_HIERARCHY_HPP

#include <iostream>


class ColorInterface
{
  public:
    virtual ~ColorInterface() noexcept = default;

    virtual void draw() const = 0;
};

class Color1 final : public ColorInterface
{
  public:
    // Keyword "override" must be at the end.
    void draw() const override
    {
        std::cout << "This is a shape drawn in Color1." << std::endl;
    }
};

#endif // IMPLEMENTATION_HIERARCHY_HPP
