#include "05_flyweight/flyweight_shared.hpp"


FlyweightShared::FlyweightShared(uint8_t code)
    : m_character(code)
{
    std::cout << "I'm the FlyweightShared. Here the constructor." <<
        std::endl;

    m_character = code;
}

char FlyweightShared::get_shared_data()
{
    return m_character;
}
