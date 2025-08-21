#ifndef ORIGINATOR_INTERFACE_HPP
#define ORIGINATOR_INTERFACE_HPP

#include "11_memento/memento_interface.hpp"

#include <memory>


namespace Memento
{

class OriginatorInterface
{
  public:
    virtual ~OriginatorInterface() = default;

    // Default c'tors and operator= overloads, both copy and move.
    
    virtual std::unique_ptr<MementoInterface> create_memento() const = 0;
};

} // namespace Mememnto


#endif // ORIGINATOR_INTERFACE_HPP
