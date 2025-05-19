#ifndef CONCRETE_PRODUCT_HPP
#define CONCRETE_PRODUCT_HPP

#include "04_factory_method/product.hpp"


namespace Factory
{

class ConcreteProduct final : public Product
{
  public:
    ConcreteProduct();

    void operationX() const override;
};

} // namespace Factory

#endif // CONCRETE_PRODUCT_HPP
