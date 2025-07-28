#ifndef CONCRETE_CREATOR_HPP
#define CONCRETE_CREATOR_HPP

#include "04_factory_method/creator.hpp"


namespace Factory
{

class ConcreteCreator final : public Creator
{
  public:
    ConcreteCreator();

    // Default d'tor, c'tors and operator= overloads, both copy and move.
    // Then the copy will follow the same parent's rule.

  protected:
    std::unique_ptr<Product> createProduct() const override;
};

} // namespace Factory


#endif // CONCRETE_CREATOR_HPP
