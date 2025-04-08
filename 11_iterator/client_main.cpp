#include "11_iterator/aggregate.hpp"
#include "11_iterator/iterator_interface.hpp"

#include <iostream>
#include <string>


int main()
{
    {
        Aggregate<int> myAggregate;
        myAggregate.addItem(0);
        myAggregate.addItem(10);

        auto iterator = myAggregate.createIterator();
        while( !(iterator->isDone()) )
        {
            std::cout << "Value: " << iterator->currentItem() << std::endl;
            iterator->next();
        }
    }

    {
        Aggregate<std::string> myAggregate;
        myAggregate.addItem("CIAO");
        myAggregate.addItem("mondo");

        auto iterator = myAggregate.createIterator();
        while( !(iterator->isDone()) )
        {
            std::cout << "Value: " << iterator->currentItem() << std::endl;
            iterator->next();
        }
    }    

    return 0;
}