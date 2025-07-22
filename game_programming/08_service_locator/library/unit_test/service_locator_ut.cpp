#include "08_service_locator/service_locator.hpp"

#include <gtest/gtest.h>


using namespace ServiceLocatorNS;

class ServiceLocatorFixture : public ::testing::Test
{
  protected:
    ~ServiceLocatorFixture()
    {}

    ServiceLocatorFixture()
    {}

    void SetUp()
    {}

    void TearDown()
    {}
};

TEST_F(ServiceLocatorFixture, test_name)
{
    ServiceLocator locator;
    Service service_provided;
    locator.provideService(&service_provided);

    Service& service = locator.getService();
    service.do_service();
}