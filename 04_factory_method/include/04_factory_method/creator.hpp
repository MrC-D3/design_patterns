#ifndef CREATOR_HPP
#define CREATOR_HPP

#include <iostream>

#include "04_factory_method/product.hpp"


class Creator
{
  public:
    virtual void do_the_logic();

  protected:
    // This is the Factory method.
    virtual Product* createProduct() = 0;

  private:
    Product* m_product = nullptr;
};

#endif
