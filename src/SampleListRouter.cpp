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

void SampleListRouter::Register(hv::HttpService &router)
{
    router.GET("/api/sample_list/get_all", SampleListHandler::get_all);
    router.POST("/api/sample_list/insert", SampleListHandler::insert);
    router.POST("/api/sample_list/update", SampleListHandler::update);
    router.POST("/api/sample_list/remove/{id}", SampleListHandler::remove);
    router.GET("/api/sample_list/get/{id}", SampleListHandler::get);
    router.GET("/api/sample_list/get_all_by_queue/{queue_number}", SampleListHandler::get_all_by_queue);
    router.POST("/api/sample_list/delete", SampleListHandler::batchDelete);
    router.POST("/api/sample_list/analyse", SampleListHandler::batchAnalyse);
    router.POST("/api/sample_list/analyse_queue/{queue_number}", SampleListHandler::analyseQueue);
    router.POST("/api/sample_list/analyse_stop", SampleListHandler::analyseStop);
}
