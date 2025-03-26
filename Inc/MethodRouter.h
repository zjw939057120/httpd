//
// Created by zjw93 on 2025/3/26.
//

#ifndef HTTPD_METHODROUTER_H
#define HTTPD_METHODROUTER_H

#include "HttpService.h"

class MethodRouter {
public:
    static void Register(hv::HttpService &router);
};


#endif //HTTPD_METHODROUTER_H
