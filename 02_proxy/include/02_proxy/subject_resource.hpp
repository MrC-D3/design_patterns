#ifndef SUBJECT_RESOURCE_HPP
#define SUBJECT_RESOURCE_HPP

#include <string>
#include <iostream>


class SubjectResource
{
  public:

    SubjectResource(std::string url)
      : m_url(url)
    {}

    virtual ~SubjectResource() {};

    void trivial_request()
    {
        std::cout << "I'm the Subject. This request doesn't need to open the \
          Resource." << std::endl;
    }

    virtual void access() = 0;

  protected:
    std::string m_url;
};

#endif
