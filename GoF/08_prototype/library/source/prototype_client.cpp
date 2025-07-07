#include "08_prototype/prototype_client.hpp"
#include "08_prototype/PrototypeConcrete.hpp"


namespace PrototypeClient
{
    
PrototypeClient::PrototypeClient()
{
    m_prototypes[0] = std::make_unique<PrototypeConcrete1>();
    m_prototypes[1] = std::make_unique<PrototypeConcrete2>();
}

const std::array<std::unique_ptr<PrototypeInterface>, 2>& 
  PrototypeClient::get_prototypes()
{
    return m_prototypes;
}

} // namespace PrototypeClient