#include "05_observer/observer.hpp"
#include "05_observer/subject.hpp"

#include <iostream>


int main()
{
    using namespace ObserverNS;

    /*
    ** Solution 01: Classic.
    */
    // Need shared_ptr<> for shared_from_this() in attach().
    auto mySubject = std::make_shared<Subject>();
    {
      // Need shared_ptr<> for shared_from_this() in d'tor.
      auto myObserver = std::make_shared<Observer>();

      mySubject->attach(myObserver);

      mySubject->setState(1);

      std::cout << "Observer didn't change Subject's state: " << 
        mySubject->getState() << ".\n";
    }

    mySubject->setState(2);

    /*
    ** Solution 02: Thread Safe.
    ** From "Tony Van Eerd: Thread-safe Observer Pattern - You're doing it wrong".
    */

    return 0;
}