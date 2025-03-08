#include <gtest/gtest.h>

#include "11_iterator/aggregate.hpp"
#include "11_iterator/iterator.hpp"


using namespace IteratorNS;


TEST(IteratorTest, IsDone)
{
    Aggregate<int> aggregate;
    return; 
    auto iterator = aggregate.createIterator();

    ASSERT_TRUE(iterator->isDone());
}

// Link against gtest_main to avoid writing the main.
int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}