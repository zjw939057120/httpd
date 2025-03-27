//
// Created by zjw93 on 2025/3/26.
//

#include "CalibrationModel.h"
#include <iostream>

using namespace sqlite_orm;

CalibrationModel::CalibrationModel() {

}

// 全局变量 storage
static auto storage = make_storage("../etc/database.db",
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
                                              make_column("calibration_order",
                                                          &CalibrationTable::calibration_order),
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


size_t CalibrationModel::get_all(std::vector<CalibrationTable> &list) {
    list = storage.get_all<CalibrationTable>();
    return list.size();
}

int CalibrationModel::insert(CalibrationTable &data) {
    return storage.insert(data);
}

bool CalibrationModel::get(CalibrationTable &data, size_t id) {
    try {
        data = storage.get<CalibrationTable>(id);
        return true;
    } catch (std::system_error e) {
        std::cout << e.what() << std::endl;
        return false;
    } catch (...) {
        std::cout << "unknown exeption" << std::endl;
        return false;
    }
}

void CalibrationModel::remove(size_t id) {
    storage.remove<CalibrationTable>(id);
}
