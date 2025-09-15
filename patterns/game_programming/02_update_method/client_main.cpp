#include "02_update_method/updatable_concrete.hpp"
#include <iostream>
#include <thread>


int main()
{
    using namespace UpdateMethodNS;

    UpdatableConcrete1 updatable{0, 0.024};

    constexpr uint8_t fps = 24;
    constexpr double ms_per_update = 1'000.0 / fps;
    for(uint8_t i = 0; i < 80; i++)
    {
        updatable.update(ms_per_update);
        auto position = updatable.getPosition();

        // Render phase.
        uint8_t pos = static_cast<uint8_t>(position);
        std::string screen(81, ' '); // 80 chars + newline
        screen[pos] = '*';
        std::cout << "\r" << screen << std::flush; // overwrite line
        std::this_thread::sleep_for( std::chrono::milliseconds(250) );
    }
    std::cout << "\n";

    return 0;
}