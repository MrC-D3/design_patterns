#ifndef AGGREGATE_INTERFACE_HPP
#define AGGREGATE_INTERFACE_HPP

#include "11_iterator/iterator_interface.hpp"


template <typename Item>
class AggregateInterface
{
  public:
    virtual IteratorInterface<Item>* createIterator() = 0;
};

#endif