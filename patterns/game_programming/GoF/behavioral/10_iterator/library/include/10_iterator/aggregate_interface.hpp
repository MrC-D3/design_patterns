// An Aggregate/Container/Collection is a box of pre-made values in memory.
//  If you want the values to be created on-demand, consider the libraries
//  coroutine and generator available since C++20. E.g.:
//   experimental::generator<int> infinite_numbers() {
//       int i = 1;
//       while (true) {  // INFINITE sequence!
//           co_yield i++;
//       }
//   }
//   auto values = infinite_numbers();  // This is fine! No infinite memory used

#ifndef AGGREGATE_INTERFACE_HPP
#define AGGREGATE_INTERFACE_HPP

#include <memory>

#include "10_iterator/iterator_interface.hpp"


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