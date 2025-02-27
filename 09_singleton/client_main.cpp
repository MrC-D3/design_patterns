#include "09_singleton/singleton.hpp"


int main()
{
    Singleton* myPtr = Singleton::get_istance();

    myPtr->print_counter();

    Singleton* myPtr2 = Singleton::get_istance();

    myPtr2->print_counter();

    return 0;
}