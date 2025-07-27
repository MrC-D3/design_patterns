#include "11_object_pool/object_pool.hpp"

#include <gtest/gtest.h>


class ObjectPoolFixture : public ::testing::Test
{
  protected:
    ~ObjectPoolFixture()
    {}

    ObjectPoolFixture()
    {}

    void SetUp()
    {}

    void TearDown()
    {}
};

TEST_F(ObjectPoolFixture, test_name)
{
    using namespace ObjectPoolNS;
    ObjectPool pool;

    pool.allocate(1);
    pool.allocate(2);
    pool.allocate(3);

    pool.all_do_something();
}