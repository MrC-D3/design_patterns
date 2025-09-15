#ifndef CONCRETE_PRODUCT_HPP
#define CONCRETE_PRODUCT_HPP

#include "02_factory_method/product.hpp"


namespace Factory
{

class ConcreteProduct final : public Product
{
  public:
    ConcreteProduct();

    // Default d'tor, c'tors and operator= overloads, both copy and move.

    void operationX() const override;
};

} // namespace Factory

#endif // CONCRETE_PRODUCT_HPP
