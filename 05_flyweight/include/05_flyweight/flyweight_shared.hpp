#ifndef FLYWEIGHT_SHARED_HPP
#define FLYWEIGHT_SHARED_HPP

#include <cstdint>


namespace Flyweight
{

class FlyweightShared
{
  public:
    // The input parameter is a basic type, so pass it by value.
    explicit FlyweightShared(const std::uint8_t code);

    // Default d'tor, c'tors and operator= overloads, for both value and move. 

    // Returning a const means the returned valued cannot be modified.
    // It has sense for references/pointers, but not for values.
    // For values, you return a copy, so the const qualifier is ignored.
    char get_shared_data() const;

  private:
    // Pretend it's the image of a character.
    char m_character{0};
};

} // namespace Flyweight


#endif // FLYWEIGHT_SHARED_HPP
