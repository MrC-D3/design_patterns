#include "04_factory_method/concrete_product.hpp"


ConcreteProduct::ConcreteProduct()
{
    std::cout << "I'm the Concrete Product." << std::endl;
}

void ConcreteProduct::operationX()
{
    std::cout << "I'm the Concrete Product. This is one of my operations." <<
        std::endl;
}
