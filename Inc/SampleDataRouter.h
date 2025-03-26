//
// Created by zjw93 on 2025/3/26.
//

#ifndef HTTPD_SAMPLEDATAROUTER_H
#define HTTPD_SAMPLEDATAROUTER_H

#include "HttpService.h"

class SampleDataRouter {
public:
    static void Register(hv::HttpService &router);
};


#endif //HTTPD_SAMPLEDATAROUTER_H
