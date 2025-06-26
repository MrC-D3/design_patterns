// Not only for rendering, the Double Buffer can be used to syncronize graphic 
//  elements too: imagine if A reaches B, B moves A to C; but, if you update A's
//  state to be on B and in the same iteration you make B able to see that A is
//  already on B, you'd lose the frame of A on B. Double Buffer helps to not
//  depend on the sequence you update each updatable object.

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