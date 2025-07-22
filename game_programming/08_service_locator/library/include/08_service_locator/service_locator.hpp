#ifndef SERVICE_LOCATOR_HPP
#define SERVICE_LOCATOR_HPP

#include <cassert>


namespace ServiceLocatorNS
{

class ServiceInterface
{
  public:
    virtual ~ServiceInterface() = default;

    virtual void do_service() = 0;
};

class Service : public ServiceInterface
{
  public:
    // Default d'tor, c'tors and operator= overloads, both copy and move.

    // Use Decorator pattern if you want the Service to log its events.
    void do_service() override;
};

class ServiceLocator
{
  public:
    // Default d'tor, c'tors and operator= overloads, both copy and move.

    // Method called at init, taking the instance from the system.
    // E.g.: mobile games may get AudioService differently than desktop games.
    static void provideService(Service* service);

    // Called to use the service; e.g. AudioService called by AI, UI, etc.
    static Service& getService();

  private:
    static Service* m_service;
};

} // namespace ServiceLocatorNS


#endif // SERVICE_LOCATOR_HPP