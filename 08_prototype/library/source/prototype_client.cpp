#include "08_prototype/prototype_client.hpp"
#include "08_prototype/PrototypeConcrete1.hpp"
#include "08_prototype/PrototypeConcrete2.hpp"


PrototypeClient::PrototypeClient()
{
    m_prototypes[0] = new PrototypeConcrete1();
    m_prototypes[1] = new PrototypeConcrete2();
}

std::array<PrototypeInterface*, 2>& PrototypeClient::get_prototypes()
{
    return m_prototypes;
}
