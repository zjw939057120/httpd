//
// Created by zjw93 on 2025/3/26.
//

#include "QueueListRouter.h"

#include "CalibrationHandler.h"
#include "MethodListHandler.h"
#include "SystemHandler.h"
#include "QueueListHandler.h"
#include "SampleListHandler.h"
#include "SampleDataHandler.h"
#include "ConfigurationHandler.h"
#include "SystemHandler.h"
#include "System.h"

void QueueListRouter::Register(hv::HttpService &router) {
    router.GET("/api/queue_list/get_all", QueueListHandler::get_all);
    router.GET("/api/queue_list/insert", QueueListHandler::insert);
    router.GET("/api/queue_list/update", QueueListHandler::update);
    router.GET("/api/queue_list/remove", QueueListHandler::remove);
    router.GET("/api/queue_list/get", QueueListHandler::get);
}
