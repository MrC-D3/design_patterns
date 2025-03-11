#include "12_observer/observer.hpp"
#include "12_observer/subject.hpp"

#include <gtest/gtest.h>


using namespace ObserverNS;

TEST(ObserverTestSuite, SubjectSetState)
{
    auto mySubject = std::make_shared<Subject>();

    // C++ exception with description "bad_weak_ptr" thrown in the test body.
    auto myObserver = std::make_shared<Observer>( mySubject );
return;
    mySubject->setState(1);

    ASSERT_EQ(mySubject->getState(), 1);
}