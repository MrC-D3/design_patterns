#ifndef AGGREGATE_HPP
#define AGGREGATE_HPP

#include "11_iterator/aggregate_interface.hpp"
#include "11_iterator/iterator.hpp"

#include <vector>


template <typename Item>
class Aggregate : public AggregateInterface<Item>
{
  public:
    IteratorInterface<Item>* createIterator() override;
    // Other possible Iterator-s can be created, as other Aggregate-s.

    void addItem(Item newItem);
    int size();
    Item getItem(int index);

  private:
    std::vector<Item> m_elements;
};


template<typename Item>
IteratorInterface<Item>* Aggregate<Item>::createIterator()
{
    return new Iterator<Item>(this);
}

template<typename Item>
int Aggregate<Item>::size()
{
    return m_elements.size();
}

template<typename Item>
Item Aggregate<Item>::getItem(int index)
{
    return m_elements[index];
}

template<typename Item>
void Aggregate<Item>::addItem(Item newItem)
{
    m_elements.push_back(newItem);
}

#endif