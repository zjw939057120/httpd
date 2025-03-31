//
// Created by zjw93 on 2025/3/26.
//

#include "SampleListRouter.h"

#include "CalibrationHandler.h"
#include "MethodListHandler.h"
#include "SystemHandler.h"
#include "QueueListHandler.h"
#include "SampleListHandler.h"
#include "SampleDataHandler.h"
#include "ConfigurationHandler.h"
#include "SystemHandler.h"
#include "System.h"

void SampleListRouter::Register(hv::HttpService &router) {
    router.GET("/api/sample_list/get_all", SampleListHandler::get_all);
    router.GET("/api/sample_list/insert", SampleListHandler::insert);
    router.GET("/api/sample_list/update", SampleListHandler::update);
    router.GET("/api/sample_list/remove/{id}", SampleListHandler::remove);
    router.GET("/api/sample_list/get/{id}", SampleListHandler::get);
}
