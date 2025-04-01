#include "13_state/context.hpp"
#include "13_state/state_interface.hpp"

#include <gtest/gtest.h>
#include <gmock/gmock.h>


using namespace State;
using ::testing::AtLeast; 

class State1Mock : public StateInterface
{
  public:
    // Base class doesn't have a default c'tor, so Derived class must call it.
    State1Mock() : StateInterface(nullptr) {};

    MOCK_METHOD(void, do_something, (), (override));
    MOCK_METHOD(void, do_something_else, (), (override));
};

TEST(StateTestSuite, GeneralTest)
{
    // Init.
    Context context;
    auto state1 = std::make_unique<State1Mock>();

    // Prepare EXPECT_s.
    EXPECT_CALL(*state1, do_something)
      .Times(AtLeast(1));

    // Call.
    context.set_state( std::move(state1) );
    context.do_something();

    // Memory freed by unique_ptr (otherwise, warning from Gmock).
}