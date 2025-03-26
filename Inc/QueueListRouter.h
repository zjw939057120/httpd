//
// Created by zjw93 on 2025/3/26.
//

#ifndef HTTPD_QUEUELISTROUTER_H
#define HTTPD_QUEUELISTROUTER_H

#include "HttpService.h"

class QueueListRouter {
public:
    static void Register(hv::HttpService &router);
};


#endif //HTTPD_QUEUELISTROUTER_H
