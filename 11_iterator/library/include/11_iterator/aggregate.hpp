#ifndef AGGREGATE_HPP
#define AGGREGATE_HPP

#include "11_iterator/aggregate_interface.hpp"

#include <vector>


template <typename Item>
class Aggregate : public AggregateInterface
{
  public:
    IteratorInterface* createIterator() override;
    // Other possible Iterator-s can be created, as other Aggregate-s.

    void addItem(Item newItem);
    int size();
    Item getItem(int index);

  private:
    std::vector<Item> m_elements;
};

#endif