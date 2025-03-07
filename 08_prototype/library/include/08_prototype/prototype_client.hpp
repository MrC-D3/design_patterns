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

    // I don't think it can work consistently: once called, you can't recall it.
    const std::shared_ptr<
      std::array<std::unique_ptr<
        PrototypeInterface>, 2
      >
    >& get_prototypes();

  private:
    std::shared_ptr<
      std::array<
        std::unique_ptr<PrototypeInterface>, 2
      >
    > m_prototypes;
};

} // namespace PrototypeClient


#endif // PROTOTYPE_CLIENT_HPP