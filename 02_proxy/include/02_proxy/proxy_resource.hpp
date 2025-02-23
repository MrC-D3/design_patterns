#ifndef PROXY_RESOURCE_HPP
#define PROXY_RESOURCE_HPP

#include <iostream>
#include "subject_resource.hpp"
#include "real_subject_resource.hpp"

class ProxyResource : public SubjectResource
{
  public:
    ProxyResource(std::string url)
      : SubjectResource(url)
    {
        // No need to initialize the object in the Proxy.
        std::cout << "I'm the Proxy. I don't need to open the Resource here." <<
          std::endl;
    }

    ~ProxyResource()
    {
        std::cout << "I'm the Proxy. I'm gonna delete the RealSubject if any." <<
          std::endl;

        if(m_real_subject_resource != nullptr)
        {
            delete m_real_subject_resource;
        }
    }

    void access() override
    {
        std::cout << "I'm the Proxy. I'm forwarding the request to the \
          RealSubject." << std::endl;

        // Now you actually need to load the Resource, if not already.

        if(m_real_subject_resource == nullptr)
        {
            m_real_subject_resource = new RealSubjectResource(m_url);
        }

        m_real_subject_resource->access();
    }

  private:
    RealSubjectResource* m_real_subject_resource = nullptr;
};

#endif
