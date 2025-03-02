#include "11_iterator/iterator.hpp"
#include "11_iterator/aggregate.hpp"


template <typename Item>
Iterator<Item>::Iterator(Aggregate<Item>* aggregate)
  : m_aggregate(aggregate),
    m_index(0)
{
    
}

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
bool Iterator<Item>::isDone()
{
    return (m_index >= m_aggregate->size());
}

template <typename Item>
Item* Iterator<Item>::currentItem()
{
    return m_aggregate->getItem(m_index);
}