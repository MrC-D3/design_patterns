#ifndef AGGREGATE_INTERFACE_HPP
#define AGGREGATE_INTERFACE_HPP

#include "11_iterator/iterator_interface.hpp"

#include <memory>


namespace IteratorNS
{
  
template <typename Item>
class AggregateInterface
{
  public:
    virtual ~AggregateInterface() = default;
    
    virtual std::unique_ptr<IteratorInterface<Item>> createIterator() = 0;
};

} // namespace IteratorNS


#endif // AGGREGATE_INTERFACE_HPP