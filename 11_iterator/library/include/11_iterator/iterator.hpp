#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "11_iterator/iterator_interface.hpp"


template <typename Item>
class Aggregate;

template <typename Item>
class Iterator : public IteratorInterface
{
  public:
    Iterator(Aggregate<Item>* aggregate);

    void first() override;
    void next() override;
    bool isDone() override;
    Item* currentItem() override;

  private:
    Aggregate<Item>* m_aggregate;
    int m_index;
};

#endif
