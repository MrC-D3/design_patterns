#ifndef HANDLER_INTERFACE_HPP
#define HANDLER_INTERFACE_HPP

#include <memory>

#include <vector>
#include <functional>


namespace CoR
{

/*
** Classic solution with inheritance and only 1 handler.
*/
class HandlerInterface
{
  public:
    virtual ~HandlerInterface() = default;
    explicit HandlerInterface(
      std::unique_ptr<HandlerInterface>&& next,
      const std::int32_t request);

    // Default c'tors and operator= overloads (only move because of unique_ptr).

    virtual void handleRequest(const std::int32_t request);
    virtual bool canHandle(const std::int32_t request) = 0;

  protected:
    std::unique_ptr<HandlerInterface> m_next;
    std::int32_t m_request;
};

/*
** Alternative solution with C++11 std::function.
*/
class HandlerAlternative
{
  private:
    std::vector< std::function<void(std::int32_t)> > chain;
};

} // namespace CoR


#endif // HANDLER_INTERFACE_HPP