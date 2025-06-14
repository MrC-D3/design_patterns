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