#include "01_game_loop/game_loop.hpp"


int main()
{
    using namespace GameLoopNS;

    GameLoop loop(1);

    loop.fixed_time_step_variable_rendering();
    
    loop.fixed_time_step_with_sync();

    return 0;
}

