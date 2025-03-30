//
// Created by zjw93 on 2025/3/26.
//

#include "CalibrationRouter.h"

#include "CalibrationHandler.h"
#include "MethodListHandler.h"
#include "SystemHandler.h"
#include "QueueListHandler.h"
#include "SampleListHandler.h"
#include "SampleDataHandler.h"
#include "ConfigurationHandler.h"
#include "SystemHandler.h"
#include "System.h"

void CalibrationRouter::Register(hv::HttpService &router) {
    router.GET("/api/calibration/get_all", CalibrationHandler::get_all);
    router.GET("/api/calibration/insert", CalibrationHandler::insert);
    router.GET("/api/calibration/update", CalibrationHandler::update);
    router.GET("/api/calibration/remove", CalibrationHandler::remove);
    router.GET("/api/calibration/get", CalibrationHandler::get);
}
