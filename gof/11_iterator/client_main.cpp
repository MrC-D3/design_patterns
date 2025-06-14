#include "11_iterator/aggregate.hpp"
#include "11_iterator/iterator_interface.hpp"

#include <iostream>
#include <string>


int main()
{
    using namespace IteratorNS;

    // Type int.
    {
        auto myAggregate = std::make_shared<Aggregate<std::int64_t>>();
        myAggregate->addItem(0);
        myAggregate->addItem(10);

        auto iterator = myAggregate->createIterator();
        while( !(iterator->isDone()) )
        {
            std::cout << "Value: " << iterator->currentItem() <<".\n";
            iterator->next();
        }
    }

    // Type string.
    {
        auto myAggregate = std::make_shared<Aggregate<std::string>>();
        myAggregate->addItem("CIAO");
        myAggregate->addItem("mondo");

        for(auto iterator = myAggregate->createIterator(); 
          !(iterator->isDone()); iterator->next())
        {
            std::cout << "Value: " << iterator->currentItem() << ".\n";
        }
    }    

    return 0;
}
