#include "12_observer/observer.hpp"
#include "12_observer/subject.hpp"

#include <gtest/gtest.h>


using namespace ObserverNS;

TEST(ObserverTestSuite, SubjectSetState)
{  
    auto mySubject = std::make_shared<Subject>();
    auto myObserver = std::make_shared<Observer>();

    mySubject->attach(myObserver);
    mySubject->setState(1);

    ASSERT_EQ(mySubject->getState(), 1);
}

/*
** Thread-safe solution test:
** - derive a concrete class from abstract Listener;
** - instance objects of Listener;
** - add Listeners to an instance of SubjectSafe;
** - run a thread for the SubjectSafe that changes its state;
** - run a thread for a Listener that calls for_every_change();
** - run another thread for a Listener that calls check_for_change().
*/
