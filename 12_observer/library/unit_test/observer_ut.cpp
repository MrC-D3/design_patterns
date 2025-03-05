#include "12_observer/observer.hpp"
#include "12_observer/subject.hpp"

#include <gtest/gtest.h>


TEST(ObserverTestSuite, SubjectSetState)
{
    Subject mySubject;
    Observer myObserver(&mySubject);

    mySubject.setState(1);

    ASSERT_EQ(mySubject.getState(), 1);
}