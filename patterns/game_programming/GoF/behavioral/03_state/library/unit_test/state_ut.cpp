#include "03_state/context.hpp"
#include "03_state/state_interface.hpp"

#include <gtest/gtest.h>
#include <gmock/gmock.h>


using namespace State;
using ::testing::AtLeast; 

class State1Mock : public StateInterface
{
  public:
    // Default d'tor, c'tors and operator= overloads, both copy and move.

    void do_something() override
    {
        std::cout << "I'm State1Mock. Do something.\n";
    }

    MOCK_METHOD(void, do_something_else, (), (override));
};

TEST(StateTestSuite, GeneralTest)
{
    // Init.
    auto context = std::make_shared<Context>();
    auto state1 = std::make_unique<State1Mock>();

    // EXPECT_CALL(*state1, do_something) causes a memory leak warning because 
    //  of unique_ptr. Required AllowLeak() to kill it.
    auto origin = std::cout.rdbuf();
    std::stringstream output; // std::streambuf of type std::string.
    std::cout.rdbuf(output.rdbuf());

    // Call.
    context->set_state( std::move(state1) );
    context->do_something();

    // Checks.
    EXPECT_NE( output.str().find("I'm State1Mock."), std::string::npos );

    // Restore.
    std::cout.rdbuf(origin);
}
