//
// Created by zjw93 on 2025/3/24.
//

#ifndef HTTPD_SYSTEMROUTER_H
#define HTTPD_SYSTEMROUTER_H

#include "HttpService.h"

class SystemRouter {
public:
    static void Register(hv::HttpService &router);

};


#endif //HTTPD_SYSTEMROUTER_H
