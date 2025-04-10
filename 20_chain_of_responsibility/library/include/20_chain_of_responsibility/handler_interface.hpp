#ifndef HANDLER_INTERFACE_HPP
#define HANDLER_INTERFACE_HPP


namespace CoR
{

class HandlerInterface
{
  public:
    virtual ~HandlerInterface() = default;
    explicit HandlerInterface(HandlerInterface* next);

    HandlerInterface(const HandlerInterface& origin) = default;
    HandlerInterface& operator=(const HandlerInterface& origin) = default;

    HandlerInterface(HandlerInterface&& origin) = default;
    HandlerInterface& operator=(HandlerInterface&& origin) = default;

    virtual void handleRequest(int request);
    virtual bool canHandle(int request) = 0;

  protected:
    HandlerInterface* m_next;
    int m_request{-1};
};

} // namespace CoR

#endif // HANDLER_INTERFACE_HPP