#ifndef PROTOTYPE_CONCRETE1_HPP
#define PROTOTYPE_CONCRETE1_HPP

#include "08_prototype/PrototypeInterface.hpp"

#include <cstdint>


namespace Prototype
{
  
class PrototypeConcrete1 final : public PrototypeInterface
{
  public:
    // Default d'tor, c'tors and operator= overload, both copy and move.
    
    std::unique_ptr<PrototypeInterface> clone() const override;

    void to_string() const override;
};

class PrototypeConcrete2 final : public PrototypeInterface
{
  public:    
    std::unique_ptr<PrototypeInterface> clone() const override;

    void to_string() const override;
};

} // namespace Prototype


#endif // PROTOTYPE_CONCRETE1_HPP