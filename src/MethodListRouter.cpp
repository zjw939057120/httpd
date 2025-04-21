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
    router.POST("/api/method_list/insert", MethodListHandler::insert);
    router.POST("/api/method_list/update", MethodListHandler::update);
    router.POST("/api/method_list/remove/{id}", MethodListHandler::remove);
    router.GET("/api/method_list/get/{id}", MethodListHandler::get);
    router.POST("/api/method_list/copy/{id}", MethodListHandler::copy);
    router.GET("/api/method_list/config", MethodListHandler::config);
}
