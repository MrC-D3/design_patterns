#ifndef REAL_SUBJECT_RESOURCE_HPP
#define REAL_SUBJECT_RESOURCE_HPP

#include <iostream>
#include "subject_resource.hpp"


class RealSubjectResource final : public SubjectResource
{
  public:
    explicit RealSubjectResource(const std::string& url)
      : SubjectResource{url}
    {
        // RAII principle: Resource Acquisition Is Initialization.
        std::cout << "I'm the RealSubject. I'm opening the Resource.\n";
    }

    ~RealSubjectResource()
    {
        std::cout << "I'm the RealSubject. I'm releasing the Resource.\n";
    }

    // Default c'tors and operator= overloads, both copy and move.

    void access() override
    {
        std::cout << "I'm the RealSubject. I'm accessing the Resource.\n";
    }
};


#endif
