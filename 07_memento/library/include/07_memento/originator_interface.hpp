#ifndef ORIGINATOR_INTERFACE_HPP
#define ORIGINATOR_INTERFACE_HPP

#include "07_memento/memento_interface.hpp"

#include <memory>


namespace Memento
{

class OriginatorInterface
{
  public:
    virtual std::unique_ptr<MementoInterface> create_memento() const = 0;
};

} // namespace Mememnto

#endif // ORIGINATOR_INTERFACE_HPP
