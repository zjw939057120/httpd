//
// Created by zjw93 on 2025/3/26.
//

#ifndef HTTPD_CALIBRATION_H
#define HTTPD_CALIBRATION_H

#include <cstdint>
#include <string>
#include "hv/json.hpp"

struct Calibration {

};

struct CalibrationTable {
    int id = 0;
    std::string calibration_line;
    int calibration_signalnumber = 0;
    std::string calibration_queue;
    int calibration_order = 0;
    std::string calibration_intercept;
    float calibration_A = 0;
    float calibration_B = 0;
    float calibration_C = 0;
    float calibration_regression = 0;
    float calibration_min = 0;
    float calibration_max = 0;
    int calibration_calculated = 0;

    // 从 JSON 解析到结构体
    void from_json(const nlohmann::json &j) {
        j.at("id").get_to(id);
        j.at("calibration_line").get_to(calibration_line);
        j.at("calibration_signalnumber").get_to(calibration_signalnumber);
    }

    // 从结构体转换为 JSON
    void to_json(nlohmann::json &j) const {
        j["id"] = id;
        j["calibration_line"] = calibration_line;
        j["calibration_signalnumber"] = calibration_signalnumber;
    }

};

extern Calibration m_calibration;

#endif //HTTPD_CALIBRATION_H
