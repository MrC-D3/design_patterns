#include <iostream>

#include "02_factory_method/concrete_creator.hpp"
#include "02_factory_method/concrete_product.hpp"


namespace Factory
{

ConcreteCreator::ConcreteCreator()
{
    std::cout << "I'm the Concrete Creator.\n";
}

std::unique_ptr<Product> ConcreteCreator::createProduct() const
{
    return std::make_unique<ConcreteProduct>();
}

} // namespace Factory