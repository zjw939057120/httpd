//
// Created by zjw93 on 2025/3/26.
//

#ifndef HTTPD_CALIBRATION_H
#define HTTPD_CALIBRATION_H

#include <cstdint>
#include <string>
#include "hv/json.hpp"

struct Calibration
{
};

struct CalibrationTable
{
    int id = 0;                        // 标定表ID
    std::string calibration_line;      // 标定线名称
    int calibration_signalnumber = 0;  // 标定信号编号
    std::string calibration_queue;     // 标定队列名称
    int calibration_order = 0;         // 标定顺序
    std::string calibration_intercept; // 标定截距
    float calibration_A = 0;           // 标定参数A
    float calibration_B = 0;           // 标定参数B
    float calibration_C = 0;           // 标定参数C
    float calibration_regression = 0;  // 标定回归系数
    float calibration_min = 0;         // 标定最小值
    float calibration_max = 0;         // 标定最大值
    int calibration_calculated = 0;    // 标定计算标志 (0: 未计算, 1: 已计算)

    // 从 JSON 解析到结构体
    void from_json(const nlohmann::json &j)
    {
        j.at("id").get_to(id);
        j.at("calibration_line").get_to(calibration_line);
        j.at("calibration_signalnumber").get_to(calibration_signalnumber);
        j.at("calibration_queue").get_to(calibration_queue);
        j.at("calibration_order").get_to(calibration_order);
        j.at("calibration_intercept").get_to(calibration_intercept);
        j.at("calibration_A").get_to(calibration_A);
        j.at("calibration_B").get_to(calibration_B);
        j.at("calibration_C").get_to(calibration_C);
        j.at("calibration_regression").get_to(calibration_regression);
        j.at("calibration_min").get_to(calibration_min);
        j.at("calibration_max").get_to(calibration_max);
        j.at("calibration_calculated").get_to(calibration_calculated);
    }

    // 从结构体转换为 JSON
    void to_json(nlohmann::json &j)
    {
        j["id"] = id;
        j["calibration_line"] = calibration_line;
        j["calibration_signalnumber"] = calibration_signalnumber;
        j["calibration_queue"] = calibration_queue;
        j["calibration_order"] = calibration_order;
        j["calibration_intercept"] = calibration_intercept;
        j["calibration_A"] = calibration_A;
        j["calibration_B"] = calibration_B;
        j["calibration_C"] = calibration_C;
        j["calibration_regression"] = calibration_regression;
        j["calibration_min"] = calibration_min;
        j["calibration_max"] = calibration_max;
        j["calibration_calculated"] = calibration_calculated;
    }
};

extern Calibration m_calibration;

#endif // HTTPD_CALIBRATION_H
