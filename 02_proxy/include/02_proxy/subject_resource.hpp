#ifndef SUBJECT_RESOURCE_HPP
#define SUBJECT_RESOURCE_HPP

#include <string>
#include <iostream>


class SubjectResource
{
  public:
    // A single-parameter-c'tor is a converting c'tor by default.
    // Use explicit to avoid it.
    explicit SubjectResource(const std::string& url)
      : m_url{url}
    {}

    virtual ~SubjectResource() noexcept = default;

    // Default c'tors and operator= overloads, both copy and move.

    void trivial_request() const
    {
        std::cout << "I'm the Subject. This request doesn't need to open the \
          Resource.\n";
    }

    // Can't be const because it can modify data class in Proxy derived class.
    virtual void access() = 0;

  protected:
    std::string m_url;
};

#endif
