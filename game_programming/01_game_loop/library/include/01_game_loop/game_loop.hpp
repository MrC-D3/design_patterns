#ifndef FRAME_RATE_HPP
#define FRAME_RATE_HPP

#include <cstdint>


namespace GameLoopNS
{

class GameLoop
{
  public:
    // Default d'tor, c'tors and operator= overloads, both copy and move.
    GameLoop(std::uint8_t fps = 24);

    // The most adaptable, but also the most complex: on faster computers the 
    //  game runs smooth; while, on slower ones, the game drops frames.
    void fixed_time_step_variable_rendering();

    // On faster computers, the loop can be delayed to keep the step; while, on
    //  slower ones, the gameplay slows down because no frames drop.
    // Good for mobile games, because the delay saves battery.
    void fixed_time_step_with_sync();

    // Fixed-Time-Step solution fails if the time to update takes longer than 
    //  the step, but Variable-Time-Step makes the physic instable.

    // Design decision on which loop relys on:
    //  platform's (e.g. browser) VS game engine's VS custom loop.
    // With libraries, you own the main game loop and call into the library; an
    //  engine owns the loop and calls into your code.

  private:
    void processInput();
    // Process AI and physics, usually in this order.
    void update();
    void render(double delay = 0.0);

    double MS_PER_UPDATE;
    bool running{true};
    double bulletX{0.0};
    double bulletSpeed{0.024};
};

} // namespace GameLoopNS


#endif // FRAME_RATE_HPP