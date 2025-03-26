//
// Created by zjw93 on 2025/3/26.
//

#include "SystemRouter.h"
#include <System.h>
#include <SystemHandler.h>

#include "handler.h"
#include <thread>   // import std::thread
#include <chrono>   // import std::chrono

#include "hbase.h"
#include "htime.h"
#include "hfile.h"
#include "hstring.h"
#include "EventLoop.h" // import setTimeout, setInterval

void SystemRouter::Register(hv::HttpService &router) {
    /* Static file service */
    // curl -v http://ip:port/
    if (g_system.debug) {
        router.Static("/", "../html/start");
        router.Static("/dist", "../html/dist");
    } else {
        router.Static("/", "./html/start");
        router.Static("/dist", "./html/dist");
    }

    router.GET("/json/menu.js", SystemHandler::menu);

    router.GET("/json/test.js", SystemHandler::test);
}
