#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "11_iterator/iterator_interface.hpp"

#include <cstdint>


namespace IteratorNS
{
  
template <typename Item>
class Aggregate;

template <typename Item>
class Iterator final : public IteratorInterface<Item>
{
  public:
    explicit Iterator(const std::shared_ptr<Aggregate<Item>>& aggregate);
    // Default d'tor, c'tors and operator= overloads, both copy and move.

    void first() override;
    void next() override;
    bool isDone() const override;
    Item currentItem() const override;

  private:
    std::shared_ptr<Aggregate<Item>> m_aggregate;
    std::int64_t m_index{0};
};


template <typename Item>
Iterator<Item>::Iterator(const std::shared_ptr<Aggregate<Item>>& aggregate)
: m_aggregate{aggregate}
{}

template <typename Item>
void Iterator<Item>::first()
{
    m_index = 0;
}

template <typename Item>
void Iterator<Item>::next()
{
    m_index += 1;
}

template <typename Item>
bool Iterator<Item>::isDone() const
{
    return (m_index >= m_aggregate->size());
}

template <typename Item>
Item Iterator<Item>::currentItem() const
{
    return m_aggregate->getItem(m_index);
}

} // namespace IteratorNS


#endif // ITERATOR_HPP
