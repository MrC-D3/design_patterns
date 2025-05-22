#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include <iostream>


namespace Factory
{

class Product
{
  public:
    virtual ~Product() = default;

    // Default c'tors and operator= overloads, both copy and move.

    virtual void operationX() const = 0;
};

} // namespace Factory


#endif // PRODUCT_HPP
