#ifndef HANDLER_INTERFACE_HPP
#define HANDLER_INTERFACE_HPP

#include <memory>


namespace CoR
{

class HandlerInterface
{
  public:
    virtual ~HandlerInterface() = default;
    explicit HandlerInterface(std::unique_ptr<HandlerInterface>&& next,
      const std::int32_t request);

    HandlerInterface(const HandlerInterface& origin) = delete;
    HandlerInterface& operator=(const HandlerInterface& origin) = delete;

    HandlerInterface(HandlerInterface&& origin) = default;
    HandlerInterface& operator=(HandlerInterface&& origin) = default;

    virtual void handleRequest(const std::int32_t request);
    virtual bool canHandle(const std::int32_t request) = 0;

  protected:
    std::unique_ptr<HandlerInterface> m_next;
    std::int32_t m_request;
};

} // namespace CoR

#endif // HANDLER_INTERFACE_HPP