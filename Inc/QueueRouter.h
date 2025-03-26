//
// Created by zjw93 on 2025/3/26.
//

#ifndef HTTPD_QUEUEROUTER_H
#define HTTPD_QUEUEROUTER_H

#include "HttpService.h"

class QueueRouter {
public:
    static void Register(hv::HttpService &router);
};


#endif //HTTPD_QUEUEROUTER_H
