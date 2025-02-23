#include "05_flyweight/flyweight_unshared.hpp"


FlyweightUnshared::FlyweightUnshared(uint64_t position, FlyweightShared* shared_data)
    : m_position(position),
    m_shared_data(shared_data)
{
    std::cout << "I'm the FlyweightUnshared. Here the constructor." <<
        std::endl;
}

void FlyweightUnshared::draw(std::string& canvas)
{
    canvas[m_position] = m_shared_data->get_shared_data();
}
