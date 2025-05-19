#ifndef HANDLER_CONCRETE_HPP
#define HANDLER_CONCRETE_HPP

#include "20_chain_of_responsibility/handler_interface.hpp"


namespace CoR
{

class HandlerConcrete : public HandlerInterface
{
  public:
    ~HandlerConcrete() = default;
    explicit HandlerConcrete(HandlerInterface* next, int request);

    HandlerConcrete(const HandlerConcrete& origin) = default;
    HandlerConcrete& operator=(const HandlerConcrete& origin) = default;

    HandlerConcrete(HandlerConcrete&& origin) = default;
    HandlerConcrete& operator=(HandlerConcrete&& origin) = default;

    void handleRequest(int request) override;
    bool canHandle(int request) override;
};

} // namespace CoR

#endif // HANDLER_CONCRETE_HPP
