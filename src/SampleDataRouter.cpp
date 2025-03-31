//
// Created by zjw93 on 2025/3/26.
//

#include "SampleDataRouter.h"

#include "CalibrationHandler.h"
#include "MethodListHandler.h"
#include "SystemHandler.h"
#include "QueueListHandler.h"
#include "SampleListHandler.h"
#include "SampleDataHandler.h"
#include "ConfigurationHandler.h"
#include "SystemHandler.h"
#include "System.h"

void SampleDataRouter::Register(hv::HttpService &router) {
    router.GET("/api/sample_data/get_all", SampleDataHandler::get_all);
    router.GET("/api/sample_data/insert", SampleDataHandler::insert);
    router.GET("/api/sample_data/update", SampleDataHandler::update);
    router.GET("/api/sample_data/remove/{id}", SampleDataHandler::remove);
    router.GET("/api/sample_data/get/{id}", SampleDataHandler::get);
}
