#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include "12_observer/observer_interface.hpp"
#include "12_observer/subject.hpp"

#include <memory>


namespace ObserverNS
{
  
class Observer final : public ObserverInterface
{
  public:
    // Default d'tor, c'tors and operator= overloads, both copy and move.
    
    void update() override;
};

} // namespace ObserverNS

#endif