#include "09_singleton/singleton.hpp"

#include <iostream>


namespace SingletonNS
{

Singleton& Singleton::get_instance(const std::int64_t counter) 
{
    // Local static variable: thread-safe, lazy initialization.
    static Singleton instance{counter};

    instance.m_counter += 1;

    return instance;
}

Singleton::Singleton(const std::int64_t counter)
: m_counter{counter}
{}

void Singleton::print_counter() const
{
    std::cout << "Counter value: " << m_counter << ".\n";
}

} // namespace SingletonNS
