#ifndef HV_HTTPD_ROUTER_H
#define HV_HTTPD_ROUTER_H

#include "HttpService.h"

class Router {
public:
    void Register(hv::HttpService &router);

    void RegisterSystem(hv::HttpService &router);

    void RegisterMethod(hv::HttpService &router);

    void RegisterQueue(hv::HttpService &router);
};

#endif // HV_HTTPD_ROUTER_H
