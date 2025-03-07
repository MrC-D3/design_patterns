#ifndef PROTOTYPE_CONCRETE1_HPP
#define PROTOTYPE_CONCRETE1_HPP

#include "08_prototype/PrototypeInterface.hpp"

#include <cstdint>


namespace Prototype
{
  
class PrototypeConcrete1 final : public PrototypeInterface
{
  public:
    explicit PrototypeConcrete1(const std::int64_t& state = 1);
    
    std::unique_ptr<PrototypeInterface> clone() const override;

    void to_string() const override;

  private:
    std::int64_t m_state;
};

} // namespace Prototype


#endif // PROTOTYPE_CONCRETE1_HPP