//
// Created by zjw93 on 2025/3/26.
//

#include "SystemRouter.h"

#include "handler.h"
#include "hthread.h"    // import hv_gettid
#include "hasync.h"     // import hv::async
#include "requests.h"   // import requests::async

#include "CalibrationHandler.h"
#include "MethodListHandler.h"
#include "SystemHandler.h"
#include "QueueListHandler.h"
#include "SampleListHandler.h"
#include "SampleDataHandler.h"
#include "ConfigurationHandler.h"
#include "SystemHandler.h"
#include "System.h"

void SystemRouter::Register(hv::HttpService &router) {
    /* Static file service */
    // curl -v http://ip:port/
    if (m_system.debug) {
        router.Static("/", "../html/start");
        router.Static("/dist", "../html/dist");
    } else {
        router.Static("/", "./html/start");
        router.Static("/dist", "./html/dist");
    }

    router.GET("/json/menu.js", SystemHandler::menu);
    router.GET("/json/test.js", SystemHandler::test);

    router.GET("/api/system/get_all", SystemHandler::get_all);
    router.GET("/api/system/insert", SystemHandler::insert);
    router.GET("/api/system/update", SystemHandler::update);
    router.GET("/api/system/remove/{id}", SystemHandler::remove);
    router.GET("/api/system/get/{id}", SystemHandler::get);
}
