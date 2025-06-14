#ifndef CARE_TAKER_HPP
#define CARE_TAKER_HPP

#include "07_memento/originator_interface.hpp"
#include "07_memento/memento_interface.hpp"

#include <stack>


namespace Memento
{
  
class CareTaker
{
  public:
    explicit CareTaker(const std::shared_ptr<OriginatorInterface>& originator);
    // Default d'tor, c'tors and operator= overloads, both copy and move.

    void backup();

    void undo();

  private:
    // Originator is needed because is the only one that can generate a Memento.
    std::shared_ptr<OriginatorInterface> m_originator;
    std::stack<std::unique_ptr<MementoInterface>> m_past_states;
};

} // namespace Memento


#endif // CARE_TAKER_HPP
