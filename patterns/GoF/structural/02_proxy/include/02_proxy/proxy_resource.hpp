#ifndef PROXY_RESOURCE_HPP
#define PROXY_RESOURCE_HPP

#include "subject_resource.hpp"
#include "real_subject_resource.hpp"

#include <iostream>
#include <memory>


class ProxyResource final : public SubjectResource
{
  public:
    explicit ProxyResource(const std::string& url)
      : SubjectResource{url}
    {
        // No need to initialize the object in the Proxy.
        std::cout << "I'm the Proxy. I don't need to open the Resource here.\n";
    }

    ~ProxyResource()
    {
        std::cout << "I'm the Proxy. I'm gonna delete the RealSubject if any.\n"
          ;

        // RealSubjectResource freed by the unique_ptr d'tor.
    }

    void access() override
    {
        std::cout << "I'm the Proxy. I'm forwarding the request to the \
          RealSubject.\n";

        // Now you actually need to load the Resource, if not already.
        // Exploit the operator overload of unique_ptr.
        if(!m_real_subject_resource)
        {
            m_real_subject_resource = 
              std::make_unique<RealSubjectResource>(m_url);
        }

        m_real_subject_resource->access();
    }

  private:
    std::unique_ptr<RealSubjectResource> m_real_subject_resource;
};

/*
** Alternative use-case: property proxy.
*/
template <typename T>
class Property
{
  public:
    Property(T value)
    : m_value{value}
    {}

    T operator=(T value)
    {
        return m_value = value;
    }
  private:
    T m_value;
};
// Instead of define getters/setters, wrap data member in a Property<T> class.
//  So, you can just do "obj.propertyA = value" and "auto v = obj.property".

#endif // PROXY_RESOURCE_HPP
