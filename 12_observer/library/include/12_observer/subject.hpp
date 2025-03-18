#ifndef SUBJECT_HPP
#define SUBJECT_HPP

#include "12_observer/subject_interface.hpp"

#include <cstdint>


namespace ObserverNS
{
  
class Subject final : public SubjectInterface
{
  public:    
    void setState(const std::int64_t& state);
    std::int64_t getState() const;

  private:
    std::int64_t m_state;
};

} // namesapce ObserverNS


#endif // SUBJECT_HPP