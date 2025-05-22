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

    // Default c'tors and operator= overload, for both copy and move.
    // But there's a non-movable data member, so copy will fail compilation.

    void do_the_logic();

  protected:
    // This is the Factory method, correctly return an instance of unique_ptr.
    virtual std::unique_ptr<Product> createProduct() const = 0;

  private:
    std::unique_ptr<Product> m_product;
};

} // namespace Factory


#endif // CREATOR_HPP
