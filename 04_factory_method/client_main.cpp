// Alternative options of N ConcreteCreator-s:
// 1) use template;
// 2) use a parameter in createProduct() to distinguish between Product-s.
// Design can start with Factory Method and then end up with Build or some other
//  design pattern.

#include "04_factory_method/concrete_creator.hpp"


int main()
{    
    Factory::ConcreteCreator myCreator;

    myCreator.do_the_logic();

    return 0;
}
