#include <thread>

#include "09_singleton/singleton.hpp"


void zero_function();
void ten_function();

using namespace SingletonNS;

int main()
{
    std::thread first(zero_function);
    std::thread second(ten_function);

    first.join();
    second.join();

    // Using only "auto" fails because it tries to copy the instance.
    auto& myPtr = Singleton::get_instance(100);

    // Value should be 13.
    myPtr.print_counter();

    return 0;
}

void zero_function()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    auto& myPtr = Singleton::get_instance(0);
}

void ten_function()
{
    auto& myPtr = Singleton::get_instance(10);
}