//
// Created by zjw93 on 2025/3/26.
//

#ifndef HTTPD_SAMPLEROUTER_H
#define HTTPD_SAMPLEROUTER_H

#include "HttpService.h"

class SampleRouter {
public:
    static void Register(hv::HttpService &router);
};


#endif //HTTPD_SAMPLEROUTER_H
