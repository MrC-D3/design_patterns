#include "09_singleton/singleton.hpp"

#include <iostream>


Singleton* Singleton::unique_instance = nullptr;
std::mutex Singleton::mutex;

Singleton* Singleton::get_instance(int counter)
{
    std::lock_guard<std::mutex> lock(mutex);
    
    if(unique_instance == nullptr)
    {
        unique_instance = new Singleton(counter);
    }
    else
    {
        unique_instance->m_counter += 1;
    }

    return unique_instance;
}

Singleton::Singleton(int counter)
  : m_counter(counter)
{}

void Singleton::print_counter()
{
    std::cout << "Counter value: " << m_counter << std::endl;
}

