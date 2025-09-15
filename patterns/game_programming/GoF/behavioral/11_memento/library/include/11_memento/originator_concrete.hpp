#ifndef ORIGINATOR_CONCRETE_HPP
#define ORIGINATOR_CONCRETE_HPP

#include "11_memento/originator_interface.hpp"

#include <memory>
#include <cstdint>


namespace Memento
{

class OriginatorConcrete final : 
  public OriginatorInterface, 
  public std::enable_shared_from_this<OriginatorConcrete>
{
  public:
    explicit OriginatorConcrete(const std::int64_t state = 0);
    // Default d'tor, c'tors and operator= overloads, both copy and move.

    std::unique_ptr<MementoInterface> create_memento() const override;

    void set_state(const std::int64_t state);

    void show_state() const;

  private:
    std::int64_t m_state{0};
};

} // namespace Memento


#endif // ORIGINATOR_CONCRETE_HPP
