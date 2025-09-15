#include "01_game_loop/game_loop.hpp"
#include <unistd.h>     // for STDIN_FILENO
#include <termios.h>    // for terminal input control
#include <fcntl.h>      // for fcntl(), O_NONBLOCK#include <chrono>
#include <thread>
#include <iostream>


namespace GameLoopNS
{

GameLoop::GameLoop(std::uint8_t fps)
: MS_PER_UPDATE{1000.0/fps}
{}

void GameLoop::fixed_time_step_variable_rendering()
{
    // Init variables.
    auto previous = std::chrono::steady_clock::now();
    double lag = 0.0;
    running = true;
    // Main game loop.
    while (running)
    {
        auto current = std::chrono::steady_clock::now();
        double elapsed = std::chrono::duration<double>(
          current - previous).count();
        previous = current;
        // How much delay the game's time has respect to the real's time.
        lag += elapsed;
    
        processInput();
    
        // You want to update the game world every MS_PER_UPDATE.
        while (lag >= MS_PER_UPDATE)
        {
            // Update game's state, the simulation: physic, AI, etc.
            update();
            // You need to compute all the updates you missed since last update,
            //  because each update affects the next one.  
            lag -= MS_PER_UPDATE;
        }
        // Here lag is in [0, MS_PER_UPDATE), so lag/MS_PER_UPDATE describes how
        //  close the real state is from the last state compute by update().
    
        // Show the game's state to the screen, but its called happens between 2
        //  updates, so with lag/MS_PER_UPDATE the render computes the 
        //  hypotethical real state to show based on last update and physic.
        render( lag/MS_PER_UPDATE );
    }
    std::cout << "\n";
}

void GameLoop::fixed_time_step_with_sync()
{
    running = true;

    while (running)
    {
        auto start = std::chrono::steady_clock::now();
        processInput();
        update();
        render();
        
        // Sleep if the iteration took lees time than the fixed time step.
        auto end = std::chrono::steady_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(
          end - start).count();
        auto sleep_duration = std::chrono::duration<double, std::milli>(MS_PER_UPDATE - elapsed);  
        std::this_thread::sleep_for( sleep_duration );
    }

    std::cout << "\n";
}

void GameLoop::processInput()
{    
    termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);             // save old settings
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);           // disable canonical mode & echo
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);    // apply new settings
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK); // non-blocking mode

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);    // restore old settings
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF) {
        if (ch == 'q') {
            running = false;
        }
    }
}

void GameLoop::update() 
{
    bulletX += bulletSpeed * MS_PER_UPDATE;
    if (bulletX > 80) bulletX = 0; // Wrap around after 80 chars
}

void GameLoop::render(double delay) 
{
    (void) delay;

    int pos = static_cast<int>(bulletX);
    std::string screen(81, ' '); // 80 chars + newline
    if (pos >= 0 && pos < 80)
        screen[pos] = '*';
    std::cout << "\r" << screen << std::flush; // overwrite line
}

} // namespace GameLoopNS
