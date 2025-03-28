//
// Created by zjw93 on 2025/3/26.
//

#ifndef HTTPD_CALIBRATIONMODEL_H
#define HTTPD_CALIBRATIONMODEL_H

#include "model.h"
#include "Calibration.h"

// 全局变量 storage
static auto calibrationStorage = make_storage("../etc/database.db",
                                              make_table("calibration",
                                                         make_column("id", &CalibrationTable::id,
                                                                     primary_key().autoincrement()),
                                                         make_column("calibration_line",
                                                                     &CalibrationTable::calibration_line),
                                                         make_column("calibration_signalnumber",
                                                                     &CalibrationTable::calibration_signalnumber),
                                                         make_column("calibration_queue",
                                                                     &CalibrationTable::calibration_queue),
                                                         make_column("calibration_order",
                                                                     &CalibrationTable::calibration_order),
                                                         make_column("calibration_intercept",
                                                                     &CalibrationTable::calibration_intercept),
                                                         make_column("calibration_A",
                                                                     &CalibrationTable::calibration_A),
                                                         make_column("calibration_B",
                                                                     &CalibrationTable::calibration_B),
                                                         make_column("calibration_C",
                                                                     &CalibrationTable::calibration_C),
                                                         make_column("calibration_regression",
                                                                     &CalibrationTable::calibration_regression),
                                                         make_column("calibration_min",
                                                                     &CalibrationTable::calibration_min),
                                                         make_column("calibration_max",
                                                                     &CalibrationTable::calibration_max),
                                                         make_column("calibration_calculated",
                                                                     &CalibrationTable::calibration_calculated)
                                              )
);


class CalibrationModel {

public:
    CalibrationModel();

    void to_json(nlohmann::json &j, const CalibrationTable &table) {
        j = nlohmann::json{
                {"id",                       table.id},
                {"calibration_line",         table.calibration_line},
                {"calibration_signalnumber", table.calibration_signalnumber},
                {"calibration_queue",        table.calibration_queue},
                {"calibration_order",        table.calibration_order},
                {"calibration_intercept",    table.calibration_intercept},
                {"calibration_A",            table.calibration_A},
                {"calibration_B",            table.calibration_B},
                {"calibration_C",            table.calibration_C},
                {"calibration_regression",   table.calibration_regression},
                {"calibration_min",          table.calibration_min},
                {"calibration_max",          table.calibration_max},
                {"calibration_calculated",   table.calibration_calculated},
        };
    }

};

#endif //HTTPD_CALIBRATIONMODEL_H
