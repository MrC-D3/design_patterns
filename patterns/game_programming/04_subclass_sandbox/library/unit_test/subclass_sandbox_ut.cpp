#include "04_subclass_sandbox/subclass_sandbox.hpp"

#include <gtest/gtest.h>


using namespace SubclassSandboxNS;

class SubclassSandboxFixture : public ::testing::Test
{
  protected:
    ~SubclassSandboxFixture()
    {}

    SubclassSandboxFixture()
    {}

    void SetUp()
    {}

    void TearDown()
    {}
};

TEST_F(SubclassSandboxFixture, test_name)
{
    SubclassA subclass;

    subclass.sandbox_method();
}
