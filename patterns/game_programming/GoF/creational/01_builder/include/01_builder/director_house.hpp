#ifndef DIRECTOR_TOTAL_HPP
#define DIRECTOR_TOTAL_HPP

#include "01_builder/builder_basic.hpp"
#include "01_builder/product_house.hpp"

#include <string>
#include <memory>


namespace Builder
{

class DirectorHouse
{
  public:
    DirectorHouse(std::shared_ptr<BuilderBasic> builder)
      : m_builder(builder)
    {}

    void build_house()
    {
        m_builder->build_foundations();
        m_builder->build_walls();
        m_builder->build_doors();
        m_builder->build_windows();
    }

  private:
    std::shared_ptr<BuilderBasic> m_builder;
};

} // namespace Builder


#endif // DIRECTOR_TOTAL_HPP
