#include <gtest/gtest.h>

#include "10_iterator/aggregate.hpp"
#include "10_iterator/iterator_interface.hpp"


using namespace IteratorNS;


TEST(IteratorTest, IsDone)
{
    auto aggregate = std::make_shared<Aggregate<int>>();
    auto iterator = aggregate->createIterator();

    ASSERT_TRUE(iterator->isDone());
}

// Link against gtest_main to avoid writing the main.
int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}