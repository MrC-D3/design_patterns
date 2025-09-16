#include "abstract_hierarchy.hpp"
#include "implementation_hierarchy.hpp"

#include <memory>


int main()
{
    /*
    ** Classic use-case: avoid Cartesian product between 2 class hierarchies.
    */
    {  
        auto triangle =  std::make_unique<Triangle>(
          std::make_unique<Blue>()
        );
        triangle->draw();
    }

    /*
    ** Alternative use-case: implement the PIMPL idiom.
    */
    {
        AbstractClass abstract(10);
        abstract.do_something();
    }
}
