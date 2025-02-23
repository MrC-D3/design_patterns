#include <iostream>

#include "04_factory_method/creator.hpp"


void Creator::do_the_logic()
{
    std::cout << "I'm the Creator. I'll use the Product to do the logic." <<
        std::endl;

    if(m_product == nullptr)
    {
        m_product = createProduct();
    }
    else
    {
        std::cout << "I'm the Creator. Product already created." << std::endl;
    }

    m_product->operationX();
}
