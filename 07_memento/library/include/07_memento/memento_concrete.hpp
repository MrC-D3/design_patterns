#ifndef MEMENTO_CONCRETE_HPP
#define MEMENTO_CONCRETE_HPP

#include "07_memento/memento_interface.hpp"
#include "07_memento/originator_concrete.hpp"

#include <memory>


namespace Memento
{

class MementoConcrete : public MementoInterface
{
  public:
    MementoConcrete(
      const std::unique_ptr<OriginatorConcrete>& originator, 
      const std::int64_t& state
    );

    void restore() const override;

    std::int64_t get_state() const;

  private:
    // Improvement: template the state type, so you Don't Repeat Yourself (DRY).
    std::int64_t m_state;
    std::unique_ptr<OriginatorConcrete> m_originator;
};

} // namespace Memento

#endif // MEMENTO_CONCRETE_HPP
