//
// Created by zjw93 on 2025/3/26.
//

#ifndef HTTPD_CALIBRATIONROUTER_H
#define HTTPD_CALIBRATIONROUTER_H

#include "HttpService.h"

class CalibrationRouter {
public:
    static void Register(hv::HttpService &router);
};


#endif //HTTPD_CALIBRATIONROUTER_H
