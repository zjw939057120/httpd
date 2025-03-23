//
// Created by zjw93 on 2025/3/23.
//

#ifndef HTTPD_SYSTEMHANDLER_H
#define HTTPD_SYSTEMHANDLER_H

#include "HttpService.h"

class SystemHandler {
public:
    static int menu(HttpRequest *req, HttpResponse *resp);

    static int test(HttpRequest *req, HttpResponse *resp);
};


#endif //HTTPD_SYSTEMHANDLER_H
