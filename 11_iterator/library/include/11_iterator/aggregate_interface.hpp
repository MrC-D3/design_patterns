#ifndef AGGREGATE_INTERFACE_HPP
#define AGGREGATE_INTERFACE_HPP


template <typename Item>
class IteratorInterface;

template <typename Item>
class AggregateInterface
{
  public:
    virtual IteratorInterface<Item>* createIterator() = 0;
};

#endif