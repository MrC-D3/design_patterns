#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include <iostream>


class Product
{
  public:
    virtual ~Product() = default;

    virtual void operationX() = 0;
};

#endif
