#ifndef AGGREGATE_INTERFACE_HPP
#define AGGREGATE_INTERFACE_HPP

#include "11_iterator/iterator_interface.hpp"


class AggregateInterface
{
  public:
    virtual IteratorInterface* createIterator() = 0;
};

#endif