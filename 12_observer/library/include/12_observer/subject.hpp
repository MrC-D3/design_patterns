#ifndef SUBJECT_HPP
#define SUBJECT_HPP

#include "12_observer/SubjectInterface.hpp"


class Subject : public SubjectInterface
{
  public:    
    void setState(int state);
    int getState();

  private:
    int m_state;
};

#endif