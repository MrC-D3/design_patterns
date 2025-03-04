#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "11_iterator/iterator_interface.hpp"


template <typename Item>
class Aggregate;

template <typename Item>
class Iterator : public IteratorInterface<Item>
{
  public:
    Iterator(Aggregate<Item>* aggregate = nullptr);

    void first() override;
    void next() override;
    bool isDone() override;
    Item currentItem() override;

  private:
    Aggregate<Item>* m_aggregate;
    int m_index;
};



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
Item Iterator<Item>::currentItem()
{
    return m_aggregate->getItem(m_index);
}

#endif
