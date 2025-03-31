#ifndef CONCRETE_CREATOR_HPP
#define CONCRETE_CREATOR_HPP

#include "04_factory_method/creator.hpp"


namespace Factory
{

class ConcreteCreator final : public Creator
{
  public:
    ConcreteCreator();

  protected:
    std::unique_ptr<Product> createProduct() const override;
};

} // namespace Factory

#endif // CONCRETE_CREATOR_HPP
