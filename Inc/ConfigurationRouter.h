//
// Created by zjw93 on 2025/3/26.
//

#ifndef HTTPD_CONFIGURATIONROUTER_H
#define HTTPD_CONFIGURATIONROUTER_H

#include "HttpService.h"

class ConfigurationRouter {
public:
    static void Register(hv::HttpService &router);
};


#endif //HTTPD_CONFIGURATIONROUTER_H
