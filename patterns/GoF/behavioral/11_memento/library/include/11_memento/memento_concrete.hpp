#ifndef MEMENTO_CONCRETE_HPP
#define MEMENTO_CONCRETE_HPP

#include "11_memento/memento_interface.hpp"
#include "11_memento/originator_concrete.hpp"

#include <memory>
#include <cstdint>


namespace Memento
{

class MementoConcrete final : public MementoInterface
{
  public:
    MementoConcrete(
      const std::shared_ptr<OriginatorConcrete>& originator, 
      const std::int64_t state
    );
    // Default d'tor, c'tors and operator= overloads, both copy and move.

    void restore() const override;

    std::int64_t get_state() const;

  private:
    // Improvement: template the state type, so you Don't Repeat Yourself (DRY).
    std::int64_t m_state;
    std::shared_ptr<OriginatorConcrete> m_originator;
};

} // namespace Memento


#endif // MEMENTO_CONCRETE_HPP
