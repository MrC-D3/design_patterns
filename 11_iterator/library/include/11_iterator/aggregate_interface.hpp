#ifndef AGGREGATE_INTERFACE_HPP
#define AGGREGATE_INTERFACE_HPP

#include <memory>

#include "11_iterator/iterator_interface.hpp"


namespace IteratorNS
{
  
template <typename Item>
class AggregateInterface
{
  public:
    virtual ~AggregateInterface() = default;
    // Default c'tors and operator= overloads, both copy and move.
    
    virtual std::unique_ptr<IteratorInterface<Item>> createIterator() = 0;
};

} // namespace IteratorNS


#endif // AGGREGATE_INTERFACE_HPP