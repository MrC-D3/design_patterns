#include "include/02_proxy/subject_resource.hpp"
#include "include/02_proxy/real_subject_resource.hpp"
#include "include/02_proxy/proxy_resource.hpp"


int main()
{
    // CASE 01: trivial request been made expensive.
    {
        auto resource_handle = std::make_unique<RealSubjectResource>("url");
        resource_handle->trivial_request();
    }

    // CASE 02: trivial request been made cheaper.
    {
        auto resource_handle = std::make_unique<ProxyResource>("resource_url");
        resource_handle->trivial_request();
    }

    // CASE 03: access to the resource is not affected.
    {
        auto resource_handle = std::make_unique<ProxyResource>("resource_url");
        resource_handle->access();
    }

    return 0;
}
