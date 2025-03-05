#ifndef REAL_SUBJECT_RESOURCE_HPP
#define REAL_SUBJECT_RESOURCE_HPP

#include <iostream>
#include "subject_resource.hpp"


class RealSubjectResource final : public SubjectResource
{
  public:
    explicit RealSubjectResource(const std::string& url)
      : SubjectResource(url)
    {
        // RAII principle: Resource Acquisition Is Initialization.
        std::cout << "I'm the RealSubject. I'm opening the Resource." << std::endl;
    }

    ~RealSubjectResource()
    {
        std::cout << "I'm the RealSubject. I'm releasing the Resource." <<
          std::endl;
    }

    void access() override
    {
        std::cout << "I'm the RealSubject. I'm accessing the Resource." <<
          std::endl;
    }
};

#endif
