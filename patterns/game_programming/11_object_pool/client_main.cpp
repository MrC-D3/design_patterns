#include "11_object_pool/object_pool.hpp"

int main()
{
    using namespace ObjectPoolNS;
    ObjectPool pool;

    pool.allocate(1);
    pool.allocate(2);
    pool.allocate(3);
    pool.allocate(4);

    pool.all_do_something();

    return 0;
}