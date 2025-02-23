#include <iostream>

#include "05_flyweight/flyweight_factory.hpp"


FlyweightUnshared* FlyweightFactory::create_flyweight(uint8_t code, uint64_t position)
{
    FlyweightShared* shared_data = get_flyweight_shared(code);

    return new FlyweightUnshared(position, shared_data);
}

FlyweightShared* FlyweightFactory::get_flyweight_shared(uint8_t key)
{
    std::cout << "I'm the Flyweight Factory. Do I have the element in the pool?"
        << std::endl;

    FlyweightShared* return_value = nullptr;

    auto iterator = m_flyweights_shared_pool.find(key);
    if(iterator == m_flyweights_shared_pool.end())
    {
        return_value = new FlyweightShared(key);
        m_flyweights_shared_pool.insert(
            std::pair<int, FlyweightShared*>(key, return_value)
            );
    }
    else
    {
        return_value = m_flyweights_shared_pool[key];
    }

    return return_value;
}
