#include "08_service_locator/service_locator.hpp"

#include <iostream>


namespace ServiceLocatorNS
{

/*
** Service implementation.
*/
void Service::do_service()
{
    std::cout << "I'm the Service. Doing my thing.\n";
}

/*
** ServiceLocator implementation.
*/
Service* ServiceLocator::m_service = nullptr;

void ServiceLocator::provideService(Service* service)
{
    m_service = service;
}

Service& ServiceLocator::getService()
{
    // Since you have to return a reference, you can't accept nullptr value.
    assert(m_service != nullptr);

    return *m_service;
}

} // namespace ServiceLocatorNS
