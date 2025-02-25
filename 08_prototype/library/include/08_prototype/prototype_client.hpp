#ifndef PROTOTYPE_CLIENT_HPP
#define PROTOTYPE_CLIENT_HPP

#include <array>

#include "08_prototype/PrototypeInterface.hpp"


class PrototypeClient
{
  public:
    PrototypeClient();

    std::array<PrototypeInterface*, 2>& get_prototypes();

  private:
    std::array<PrototypeInterface*, 2> m_prototypes;
};

#endif