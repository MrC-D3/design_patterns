#include "08_service_locator/service_locator.hpp"


int main()
{
    using namespace ServiceLocatorNS;
    Service provided_service;
    ServiceLocator locator;
    locator.provideService(&provided_service);

    auto service = locator.getService();
    service.do_service();

    return 0;
}