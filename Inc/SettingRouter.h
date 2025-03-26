//
// Created by zjw93 on 2025/3/26.
//

#ifndef HTTPD_SETTINGROUTER_H
#define HTTPD_SETTINGROUTER_H

#include "HttpService.h"

class SettingRouter {
public:
    static void Register(hv::HttpService &router);
};


#endif //HTTPD_SETTINGROUTER_H
