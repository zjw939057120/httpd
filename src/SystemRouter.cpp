//
// Created by zjw93 on 2025/3/24.
//

#include <SystemRouter.h>

#include "handler.h"
#include "hthread.h"    // import hv_gettid
#include "hasync.h"     // import hv::async
#include "requests.h"   // import requests::async
#include <SystemHandler.h>

void SystemRouter::Register(hv::HttpService &router) {

    router.GET("/json/menu.js", SystemHandler::menu);

    router.GET("/json/test.js", SystemHandler::test);
}
