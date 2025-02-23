#include <iostream>

#include "04_factory_method/concrete_creator.hpp"
#include "04_factory_method/concrete_product.hpp"


ConcreteCreator::ConcreteCreator()
{
    std::cout << "I'm the Concrete Creator." << std::endl;
}

Product* ConcreteCreator::createProduct()
{
    return new ConcreteProduct();
}
