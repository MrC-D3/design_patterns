#ifndef PROTOTYPE_CONCRETE2_HPP
#define PROTOTYPE_CONCRETE2_HPP

#include "08_prototype/PrototypeInterface.hpp"


namespace Prototype
{
  
class PrototypeConcrete2 final : public PrototypeInterface
{
  public:
    explicit PrototypeConcrete2(const std::int64_t& state = 2);
    
    std::unique_ptr<PrototypeInterface> clone() const override;

    void to_string() const override;

  private:
    std::int64_t m_state;
};

} // namespace Prototype


#endif