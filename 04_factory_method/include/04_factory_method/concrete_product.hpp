#ifndef CONCRETE_PRODUCT_HPP
#define CONCRETE_PRODUCT_HPP

#include "04_factory_method/product.hpp"


class ConcreteProduct : public Product
{
  public:
    ConcreteProduct();

    void operationX() override;
};

#endif
