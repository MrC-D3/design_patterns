#ifndef CONCRETE_CREATOR_HPP
#define CONCRETE_CREATOR_HPP

#include "04_factory_method/creator.hpp"


class ConcreteCreator : public Creator
{
  public:
    ConcreteCreator();

  protected:
    Product* createProduct() override;
};

#endif
