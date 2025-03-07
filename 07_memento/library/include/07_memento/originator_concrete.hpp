#ifndef ORIGINATOR_CONCRETE_HPP
#define ORIGINATOR_CONCRETE_HPP

#include "07_memento/originator_interface.hpp"

#include <memory>


namespace Memento
{

class OriginatorConcrete : public OriginatorInterface
{
  public:
    OriginatorConcrete(const std::int64_t& state = 0);

    std::unique_ptr<MementoInterface> create_memento() const override;

    void set_state(const std::int64_t& state);

    void show_state() const;

  private:
    std::int64_t m_state{0};
};

} // namespace Memento


#endif // ORIGINATOR_CONCRETE_HPP
