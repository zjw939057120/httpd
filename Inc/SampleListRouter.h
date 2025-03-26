//
// Created by zjw93 on 2025/3/26.
//

#ifndef HTTPD_SAMPLELISTROUTER_H
#define HTTPD_SAMPLELISTROUTER_H

#include "HttpService.h"

class SampleListRouter {
public:
    static void Register(hv::HttpService &router);
};


#endif //HTTPD_SAMPLELISTROUTER_H
