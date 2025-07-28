#include "02_update_method/updatable_interface.hpp"


namespace UpdateMethodNS
{

UpdatableInterface::UpdatableInterface(double start_position)
: m_position(start_position)
{}

double UpdatableInterface::getPosition()
{
    return m_position;
}

} // namespace UpdateMethodNS
