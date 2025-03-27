//
// Created by zjw93 on 2025/3/26.
//

#ifndef HTTPD_CALIBRATIONMODEL_H
#define HTTPD_CALIBRATIONMODEL_H

#include <sqlite_orm/sqlite_orm.h>
#include "Calibration.h"

class CalibrationModel {

public:
    CalibrationModel();

    size_t get_all(std::vector<CalibrationTable> &list);

    int insert(CalibrationTable &data);

    bool get(CalibrationTable &data, size_t id);

    void remove(size_t id);

public:
};

#endif //HTTPD_CALIBRATIONMODEL_H
