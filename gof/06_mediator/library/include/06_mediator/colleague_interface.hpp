#ifndef COLLEAGUE_INTERFACE_HPP
#define COLLEAGUE_INTERFACE_HPP

#include "06_mediator/mediator_interface.hpp"

#include <iostream>
#include <memory>


namespace Mediator
{

class ColleagueInterface
{
  public:
    // The Base class requires at least one virtual method.
    virtual ~ColleagueInterface() = default;

    // Default c'tors and operator= overloads, both copy and move.
    
    void set_mediator(const std::shared_ptr<MediatorInterface>& mediator);

  protected:
    std::shared_ptr<MediatorInterface> m_mediator;
};

} // namespace Mediator


#endif // COLLEAGUE_INTERFACE_HPP
