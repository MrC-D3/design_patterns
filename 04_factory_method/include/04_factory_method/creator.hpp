#ifndef CREATOR_HPP
#define CREATOR_HPP

#include "04_factory_method/product.hpp"

#include <iostream>
#include <memory>

namespace Factory
{

class Creator
{
  public:
    virtual ~Creator() = default;

    virtual void do_the_logic();

  protected:
    // This is the Factory method.
    virtual std::unique_ptr<Product> createProduct() const = 0;

  private:
    std::unique_ptr<Product> m_product;
};

} // namespace Factory

#endif // CREATOR_HPP
