//
// Created by zjw93 on 2025/3/26.
//

#include "ConfigurationRouter.h"

#include "CalibrationHandler.h"
#include "MethodListHandler.h"
#include "SystemHandler.h"
#include "QueueListHandler.h"
#include "SampleListHandler.h"
#include "SampleDataHandler.h"
#include "ConfigurationHandler.h"
#include "SystemHandler.h"
#include "System.h"

void ConfigurationRouter::Register(hv::HttpService &router) {
    router.GET("/api/configuration/get_all", ConfigurationHandler::get_all);
    router.POST("/api/configuration/insert", ConfigurationHandler::insert);
    router.POST("/api/configuration/update", ConfigurationHandler::update);
    router.POST("/api/configuration/remove/{id}", ConfigurationHandler::remove);
    router.GET("/api/configuration/get/{id}", ConfigurationHandler::get);
}
