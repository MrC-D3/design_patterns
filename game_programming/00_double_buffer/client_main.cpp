#include "00_double_buffer/double_buffer.hpp"

#include <iostream>


using namespace DoubleBufferNS;

int main()
{
    DoubleBuffer dBuffer(320, 200);

    dBuffer.draw(0, 0);
    dBuffer.swap();
    dBuffer.clear();

    for(const auto& pixel : dBuffer.get_buffer())
    {
        std::cout << pixel;
    }

    return 0;
}