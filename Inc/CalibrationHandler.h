//
// Created by zjw93 on 2025/3/26.
//

#ifndef HTTPD_CALIBRATIONHANDLER_H
#define HTTPD_CALIBRATIONHANDLER_H

#include "HttpService.h"

class CalibrationHandler {
public:
    static int get_all(HttpRequest *req, HttpResponse *resp);

    static int insert(HttpRequest *req, HttpResponse *resp);

    static int update(HttpRequest *req, HttpResponse *resp);

    static int remove(HttpRequest *req, HttpResponse *resp);

    static int get(HttpRequest *req, HttpResponse *resp);
};


#endif //HTTPD_CALIBRATIONHANDLER_H
