// Another alternative implementation of the pattern that avoids having N 
//  ConcreteCreator-s: use a parameter in createProduct() to distinguish between
//  Product-s.
// The Factory Method pattern allows those programs that know only at run-time 
//  which objects they need, to be able to create them.

#include "04_factory_method/concrete_creator.hpp"
#include "04_factory_method/concrete_product.hpp"


int main()
{    
    // Classic solution
    Factory::ConcreteCreator myCreator;
    myCreator.do_the_logic();

    // Template solution (no v-table, so better performance).
    Factory::CreatorT<Factory::ConcreteProduct> myCreatorT;
    myCreatorT.do_the_logic();

    return 0;
}
