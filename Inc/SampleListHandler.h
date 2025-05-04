//
// Created by zjw93 on 2025/3/26.
//

#ifndef HTTPD_SAMPLELISTHANDLER_H
#define HTTPD_SAMPLELISTHANDLER_H

#include "HttpService.h"

class SampleListHandler
{
public:
    static int get_all(HttpRequest *req, HttpResponse *resp);

    static int insert(HttpRequest *req, HttpResponse *resp);

    static int update(HttpRequest *req, HttpResponse *resp);

    static int remove(HttpRequest *req, HttpResponse *resp);

    static int get(HttpRequest *req, HttpResponse *resp);

    static int get_all_by_queue(HttpRequest *req, HttpResponse *resp);

    static int batchDelete(HttpRequest *req, HttpResponse *resp);

    static int batchAnalyse(HttpRequest *req, HttpResponse *resp);

    static int analyseQueue(HttpRequest *req, HttpResponse *resp);

    static int analyseStop(HttpRequest *req, HttpResponse *resp);
    
};

#endif // HTTPD_SAMPLELISTHANDLER_H
