#include "13_state/context.hpp"
#include "13_state/state_interface.hpp"

#include <gtest/gtest.h>
#include <gmock/gmock.h>


using namespace State;

class State1Mock : public StateInterface
{
    MOCK_METHOD(void, do_something, (), (override));
    MOCK_METHOD(void, do_something_else, (), (override));
};

TEST(StateTestSuite, GeneralTest)
{
    // Init.
    Context context;
    State1Mock state1;

    // Prepare EXPECT_s.
    EXPECT_CALL(state1, do_something)
      .Times(AtLeast(1));

    context.set_state(state1);
    context.do_something();
}