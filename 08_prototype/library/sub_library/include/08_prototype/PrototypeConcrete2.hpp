#ifndef PROTOTYPE_CONCRETE2_HPP
#define PROTOTYPE_CONCRETE2_HPP

#include "08_prototype/PrototypeInterface.hpp"


namespace Prototype
{
  
class PrototypeConcrete2 final : public PrototypeInterface
{
  public:    
    std::unique_ptr<PrototypeInterface> clone() const override;

    void to_string() const override;
};

} // namespace Prototype


#endif