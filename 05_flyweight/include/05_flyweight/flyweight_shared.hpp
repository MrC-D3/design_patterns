// Usually, the behavior of the original object remains in the flyweight class.
// In this case, whoever calls a flyweight’s method must also pass appropriate
// bits of the extrinsic state into the method’s parameters. On the other hand,
// the behavior can be moved to the context class, which would use the linked
// flyweight merely as a data object.


#ifndef FLYWEIGHT_SHARED_HPP
#define FLYWEIGHT_SHARED_HPP

#include <iostream>


class FlyweightShared
{
  public:
    FlyweightShared(uint8_t code);

    char get_shared_data();

  private:
    // Pretend it's the image of a character.
    char m_character = 0;
};


#endif
