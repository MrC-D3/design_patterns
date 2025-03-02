#include "11_iterator/aggregate.hpp"
#include "11_iterator/iterator.hpp"

template<typename Item>
IteratorInterface* Aggregate<Item>::createIterator()
{
    return new Iterator<Item>();
}

template<typename Item>
int Aggregate<Item>::size()
{
    return m_elements->size();
}

template<typename Item>
Item Aggregate<Item>::getItem(int index)
{
    return m_elements[index];
}

template<typename Item>
void Aggregate<Item>::addItem(Item newItem)
{
    m_elements.insert(newItem);
}
