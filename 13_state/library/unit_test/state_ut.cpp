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
    auto context = std::make_shared<Context>();
    auto state1 = std::make_unique<State1Mock>();

    // Prepare EXPECT_s.
    auto ptr = state1.get();
    EXPECT_CALL(*ptr, do_something)
      .Times(AtLeast(1));

    // Call.
    context->set_state( std::move(state1) );
    context->do_something();

    delete ptr;
}