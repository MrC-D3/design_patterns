#include "02_update_method/updatable_concrete.hpp"

#include "gtest/gtest.h"
#include "gmock/gmock.h"


using namespace UpdateMethodNS;

class UpdateMethodFixture : public ::testing::Test
{
  protected:
    ~UpdateMethodFixture()
    {}

    UpdateMethodFixture()
    {}

    void SuiteUp()
    {}

    void TearDown()
    {}
};

TEST_F(UpdateMethodFixture, update_method_test)
{
    UpdatableConcrete1 updatable{0, 0.024};

    constexpr uint8_t fps = 24;
    constexpr double ms_per_update = 1'000.0 / fps;
    updatable.update(ms_per_update);

    auto position = updatable.getPosition();
    ASSERT_EQ(position, 1.0);
}