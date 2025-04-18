//
// Created by zjw93 on 2025/3/26.
//

#include "MethodListRouter.h"

#include "CalibrationHandler.h"
#include "MethodListHandler.h"
#include "SystemHandler.h"
#include "QueueListHandler.h"
#include "SampleListHandler.h"
#include "SampleDataHandler.h"
#include "ConfigurationHandler.h"
#include "SystemHandler.h"
#include "System.h"

void MethodListRouter::Register(hv::HttpService &router) {
    router.GET("/api/method_list/get_all", MethodListHandler::get_all);
    router.GET("/api/method_list/insert", MethodListHandler::insert);
    router.GET("/api/method_list/update", MethodListHandler::update);
    router.GET("/api/method_list/remove/{id}", MethodListHandler::remove);
    router.GET("/api/method_list/get/{id}", MethodListHandler::get);
    router.GET("/api/method_list/get_filter/{id}", MethodListHandler::get_filter);
    router.GET("/api/method_list/config", MethodListHandler::config);
}
