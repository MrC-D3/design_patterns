#include "12_observer/observer.hpp"
#include "12_observer/subject.hpp"

#include <iostream>


int main()
{
    Subject mySubject;
    Observer myObserver(&mySubject);

    mySubject.setState(1);

    std::cout << "Observer didn't change Subject's state: " << 
      mySubject.getState() << std::endl;

    return 0;
}