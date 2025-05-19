#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include <iostream>


namespace Factory
{

class Product
{
  public:
    virtual ~Product() = default;

    virtual void operationX() const = 0;
};

} // namespace Factory

#endif // PRODUCT_HPP
