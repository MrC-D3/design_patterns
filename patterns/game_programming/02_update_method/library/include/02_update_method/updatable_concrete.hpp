#ifndef UPDATABLE_CONCRETE_HPP
#define UPDATABLE_CONCRETE_HPP

#include "02_update_method/updatable_interface.hpp"


namespace UpdateMethodNS
{

class UpdatableConcrete1 : public UpdatableInterface
{
  public:
    // Velocity as: position per milliseconds.
    UpdatableConcrete1(double start_position, double velocity);
    // Default d'tor, c'tors and operator= overloads, both copy and move.

    void update(double ms_per_update) override;

  private:
    double m_velocity;
};

// UpdatableConcrete2 and several other possible concrete classes, each with its
//  update() method: with acceleration, with color based on position, etc.

} // namespace UpdateMethodNS


#endif // UPDATABLE_CONCRETE_HPP