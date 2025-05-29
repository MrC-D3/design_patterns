#ifndef HANDLER_INTERFACE_HPP
#define HANDLER_INTERFACE_HPP

#include <memory>

#include <vector>
#include <functional>
#include <iostream>


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
  public:
    HandlerAlternative()
    {
        chain.push_back(
          [](const std::int32_t request){
            if(request == 0)
            {
              std::cout << "I'm Handler-0. Handling the request.\n";
              return true;
            }
            else
            {
              return false;
            }
          }
        );

        chain.push_back(
          [](const std::int32_t request){
            if(request == 1)
            {
              std::cout << "I'm Handler-1. Handling the request.\n";
              return true;
            }
            else
            {
              return false;
            }
          }
        );
    }

    void operator()(const std::int32_t request)
    {
        for(auto& handler : chain)
        {
            if( handler(request) )
            {
                break;
            }
        }
    }

  private:
    std::vector< std::function<bool(const std::int32_t)> > chain;
};

} // namespace CoR


#endif // HANDLER_INTERFACE_HPP