#include "12_observer/observer.hpp"
#include "12_observer/subject.hpp"

#include <iostream>


int main()
{
    using namespace ObserverNS;

    auto mySubject = std::make_shared<Subject>();
    auto myObserver = std::make_shared<Observer>();

    mySubject->attach(myObserver);

    mySubject->setState(1);

    std::cout << "Observer didn't change Subject's state: " << 
      mySubject->getState() << ".\n";

    return 0;
}