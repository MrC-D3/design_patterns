#include "include/02_proxy/subject_resource.hpp"
#include "include/02_proxy/real_subject_resource.hpp"
#include "include/02_proxy/proxy_resource.hpp"


int main()
{
    // CASE 01: trivial request been made expensive.
    {
        SubjectResource* resource_handle = new RealSubjectResource("resource_url");
        resource_handle->trivial_request();
        delete resource_handle;
    }

    // CASE 02: trivial request been made cheaper.
    {
        SubjectResource* resource_handle = new ProxyResource("resource_url");
        resource_handle->trivial_request();
        delete resource_handle;
    }

    // CASE 03: access to the resource is not affected.
    {
        SubjectResource* resource_handle = new ProxyResource("resource_url");
        resource_handle->access();
        delete resource_handle;
    }
}
