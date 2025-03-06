#include <iostream>

#include "04_factory_method/concrete_creator.hpp"
#include "04_factory_method/concrete_product.hpp"


namespace Factory
{

ConcreteCreator::ConcreteCreator()
{
    std::cout << "I'm the Concrete Creator." << std::endl;
}

std::unique_ptr<Product> ConcreteCreator::createProduct() const
{
    return std::make_unique<ConcreteProduct>();
}

} // namespace Factory