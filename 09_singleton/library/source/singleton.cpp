#include "09_singleton/singleton.hpp"

#include <iostream>


Singleton* Singleton::unique_instance = nullptr;

Singleton* Singleton::get_instance()
{
    if(unique_instance == nullptr)
    {
        unique_instance = new Singleton();
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

