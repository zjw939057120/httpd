//
// Created by zjw93 on 2025/3/23.
//

#ifndef HTTPD_CONFIGURATIONHANDLER_H
#define HTTPD_CONFIGURATIONHANDLER_H

#include "HttpService.h"

class ConfigurationHandler {
public:
    static int get_all(HttpRequest *req, HttpResponse *resp);

    static int insert(HttpRequest *req, HttpResponse *resp);

    static int update(HttpRequest *req, HttpResponse *resp);

    static int remove(HttpRequest *req, HttpResponse *resp);

    static int get(HttpRequest *req, HttpResponse *resp);
};


#endif //HTTPD_CONFIGURATIONHANDLER_H
