//
// Created by zjw93 on 2025/3/26.
//

#ifndef HTTPD_CALIBRATION_H
#define HTTPD_CALIBRATION_H

#include <cstdint>
#include <string>

struct Calibration {

};

struct CalibrationTable {
    int id;
    std::string calibration_line;
    int calibration_signalnumber;
    std::string calibration_queue;
    int calibration_order;
    std::string calibration_intercept;
    float calibration_A;
    float calibration_B;
    float calibration_C;
    float calibration_regression;
    float calibration_min;
    float calibration_max;
    int calibration_calculated;
};

extern Calibration m_calibration;

#endif //HTTPD_CALIBRATION_H
