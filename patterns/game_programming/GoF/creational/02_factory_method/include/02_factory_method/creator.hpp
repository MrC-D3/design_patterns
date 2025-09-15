#ifndef CREATOR_HPP
#define CREATOR_HPP

#include "02_factory_method/product.hpp"

#include <iostream>
#include <memory>


namespace Factory
{

/*
** Classic solution with inheritance.
*/
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
    // Rule of 0: 
    //  manage the memory with STL and don't write any d/c'tor or operator=.
    std::unique_ptr<Product> m_product;
};


/*
** Performance solution with Template.
*/
template <typename ProductT>
class CreatorT
{
  public:
    // Default d'tor, c'tor and operator= overloads, both copy and move.
    
    void do_the_logic()
    {
        if( !m_product )
        {
            m_product = factoryMethod();
        }

        // Add a static_assert() to guarantee ProductT::operationX exists.
        m_product->operationX();
    }

  private:
    std::unique_ptr<ProductT> factoryMethod()
    {
        return std::make_unique<ProductT>();
    }

    std::unique_ptr<ProductT> m_product;
};

} // namespace Factory


#endif // CREATOR_HPP
