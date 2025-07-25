#ifndef PROTOTYPE_CLIENT_HPP
#define PROTOTYPE_CLIENT_HPP

#include <array>

#include "08_prototype/PrototypeInterface.hpp"


namespace PrototypeClient
{

using namespace Prototype;

class PrototypeClient
{
  public:
    PrototypeClient();
    // Default d'tor, c'tors and operator= overloads, both copy and move.

    const std::array<std::unique_ptr<PrototypeInterface>, 2>& get_prototypes();

  private:
    std::array<std::unique_ptr<PrototypeInterface>, 2> m_prototypes;
};

// In game context, the Client can be a Spawner that wraps a Prototype and calls
//  clone() on it. Here a template-concept implementation in C++20.
template <typename T>
concept Clonable = requires(T a)
{
    { a.clone() } -> std::same_as<T>;
};

template <Clonable PrototypeT>
class PrototypeSpawner
{
  public:
    PrototypeT spawn()
    {
        return m_prototype.clone();
    }

  private:
    // Or you can pass it to the Spawner c'tor.
    PrototypeT m_prototype;
};


} // namespace PrototypeClient


#endif // PROTOTYPE_CLIENT_HPP