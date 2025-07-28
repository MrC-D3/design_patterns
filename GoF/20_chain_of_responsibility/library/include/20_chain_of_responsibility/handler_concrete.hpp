#ifndef HANDLER_CONCRETE_HPP
#define HANDLER_CONCRETE_HPP

#include "20_chain_of_responsibility/handler_interface.hpp"

#include <memory>


namespace CoR
{

class HandlerConcrete final : public HandlerInterface
{
  public:
    ~HandlerConcrete() = default;
    HandlerConcrete(
      std::unique_ptr<HandlerInterface>&& next, 
      const std::int32_t request);

    // Default c'tors and operator= overloads (only move because of unique_ptr).

    void handleRequest(const std::int32_t request) override;
    bool canHandle(const std::int32_t request) override;
};

} // namespace CoR


#endif // HANDLER_CONCRETE_HPP
