#include "01_game_loop/game_loop.hpp"

#include "gtest/gtest.h"
#include "gmock/gmock.h"


using namespace GameLoopNS;

class GameLoopFixture : public ::testing::Test
{
  protected:
    ~GameLoopFixture()
    {}

    GameLoopFixture()
    {}

    void SuiteUp()
    {}

    void TearDown()
    {}
};

TEST_F(GameLoopFixture, interpolate_rendering_test)
{
    GameLoop loop;
    loop.fixed_time_step_variable_rendering();
}