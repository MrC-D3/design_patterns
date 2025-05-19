#ifndef HANDLER_INTERFACE_HPP
#define HANDLER_INTERFACE_HPP

#include <memory>


namespace CoR
{

class HandlerInterface
{
  public:
    virtual ~HandlerInterface() = default;
    explicit HandlerInterface(std::unique_ptr<HandlerInterface>&& next);

    HandlerInterface(const HandlerInterface& origin) = default;
    HandlerInterface& operator=(const HandlerInterface& origin) = default;

    HandlerInterface(HandlerInterface&& origin) = default;
    HandlerInterface& operator=(HandlerInterface&& origin) = default;

    virtual void handleRequest(const std::int32_t request);
    virtual bool canHandle(const std::int32_t request) = 0;

  protected:
    std::unique_ptr<HandlerInterface> m_next;
    std::int32_t m_request{-1};
};

} // namespace CoR

#endif // HANDLER_INTERFACE_HPP