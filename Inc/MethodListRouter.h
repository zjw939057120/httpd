//
// Created by zjw93 on 2025/3/26.
//

#ifndef HTTPD_METHODLISTROUTER_H
#define HTTPD_METHODLISTROUTER_H

#include "HttpService.h"

class MethodListRouter {
public:
    static void Register(hv::HttpService &router);
};


#endif //HTTPD_METHODLISTROUTER_H
