//
// Created by zjw93 on 2025/3/23.
//

#ifndef HTTPD_METHODLISTHANDLER_H
#define HTTPD_METHODLISTHANDLER_H

#include "HttpService.h"

class MethodListHandler {
public:
    static int get_all(HttpRequest *req, HttpResponse *resp);

    static int insert(HttpRequest *req, HttpResponse *resp);

    static int update(HttpRequest *req, HttpResponse *resp);

    static int remove(HttpRequest *req, HttpResponse *resp);

    static int get(HttpRequest *req, HttpResponse *resp);

    static int get_filter(HttpRequest *req, HttpResponse *resp);
    
    static int config(HttpRequest *req, HttpResponse *resp);
};

#endif //HTTPD_METHODLISTHANDLER_H
