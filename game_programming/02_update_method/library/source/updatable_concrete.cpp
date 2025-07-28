#include "02_update_method/updatable_concrete.hpp"


namespace UpdateMethodNS
{

UpdatableConcrete1::UpdatableConcrete1(double start_position, double velocity)
: UpdatableInterface(start_position), m_velocity(velocity)
{}


void UpdatableConcrete1::update(double ms_per_update)
{
    m_position += m_velocity * ms_per_update;
    if (m_position > 80)
    {
        m_position = 0; // Wrap around after 80 chars
    }
}

} // namespace UpdateMethodNS
