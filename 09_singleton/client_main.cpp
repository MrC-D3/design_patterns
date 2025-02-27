#include <thread>

#include "09_singleton/singleton.hpp"


void zero_function();
void ten_function();

int main()
{
    std::thread first(zero_function);
    std::thread second(ten_function);

    first.join();
    second.join();

    Singleton* myPtr = Singleton::get_instance(100);

    // Value should be 12.
    myPtr->print_counter();

    return 0;
}

void zero_function()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    Singleton* myPtr = Singleton::get_instance(0);
}

void ten_function()
{
    Singleton* myPtr = Singleton::get_instance(10);
}