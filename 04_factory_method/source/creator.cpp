#include <iostream>

#include "04_factory_method/creator.hpp"

namespace Factory
{

void Creator::do_the_logic()
{
    std::cout << "I'm the Creator. I'll use the Product to do the logic.\n";

    if(!m_product)
    {
        m_product = createProduct();
    }
    else
    {
        std::cout << "I'm the Creator. Product already created.\n";
    }

    m_product->operationX();
}

} // namespace Factory
