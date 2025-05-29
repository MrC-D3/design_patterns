#ifndef AGGREGATE_HPP
#define AGGREGATE_HPP

#include "11_iterator/aggregate_interface.hpp"
#include "11_iterator/iterator.hpp"

#include <vector>


namespace IteratorNS
{
    
template <typename Item>
class Aggregate final : 
  public AggregateInterface<Item>,
  // This requires the class to be instantiated in the heap.
  public std::enable_shared_from_this<Aggregate<Item>>
{
  public:
    // Default d'tor, c'tors and operator= overloads, both copy and move.
    
    std::unique_ptr<IteratorInterface<Item>> createIterator() override;
    // Other possible Iterator-s can be created, as other Aggregate-s.

    void addItem(const Item& newItem);
    std::size_t size() const;
    Item getItem(const std::int64_t index) const;

  private:
    std::vector<Item> m_elements;
};


template<typename Item>
std::unique_ptr<IteratorInterface<Item>> Aggregate<Item>::createIterator()
{
    // Since the class is templated, compiler requires the form this->.
    return std::make_unique<Iterator<Item>>(this->shared_from_this());
}

template<typename Item>
std::size_t Aggregate<Item>::size() const
{
    return m_elements.size();
}

template<typename Item>
Item Aggregate<Item>::getItem(const std::int64_t index) const
{
    // TODO: make it more robust checking index and using optional<T>.
    return m_elements[index];
}

template<typename Item>
void Aggregate<Item>::addItem(const Item& newItem)
{
    m_elements.push_back(newItem);
}

} // namespace IteratorNS


#endif // AGGREGATE_HPP