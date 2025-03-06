#include "04_factory_method/concrete_product.hpp"


namespace Factory
{

ConcreteProduct::ConcreteProduct()
{
    std::cout << "I'm the Concrete Product." << std::endl;
}

void ConcreteProduct::operationX() const
{
    std::cout << "I'm the Concrete Product. This is one of my operations." <<
        std::endl;
}

} // namespace Factory
