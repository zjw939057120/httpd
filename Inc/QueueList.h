//
// Created by zjw93 on 2025/3/26.
//

#ifndef HTTPD_QUEUELIST_H
#define HTTPD_QUEUELIST_H

#include <cstdint>
#include <string>
#include "hv/json.hpp"

struct QueueList
{
};

struct QueueListTable
{
    int id = 0;                             // 队列列表ID
    int queue_number = 0;                   // 队列编号
    int queue_signalnumber = 0;             // 队列信号编号
    std::string queue_name;                 // 队列名称
    std::string queue_comment;              // 队列备注
    int queue_element = 0;                  // 队列元素数量
    float queue_blanco = 0;                 // 空白值
    float queue_yield = 0;                  // 收率
    int queue_calibrationqueue = 0;         // 标定队列编号
    int queue_calibration_signalnumber = 0; // 标定信号编号
    int queue_calibration_order = 0;        // 标定顺序
    int queue_intercept = 0;                // 截距
    float queue_calibrationa = 0;           // 标定参数A
    float queue_calibrationb = 0;           // 标定参数B
    float queue_calibrationc = 0;           // 标定参数C
    float queue_regression = 0;             // 回归系数
    int queue_calibration_min = 0;          // 标定最小值
    int queue_calibration_max = 0;          // 标定最大值
    int queue_timewindow = 0;               // 时间窗口
    int queue_treshold0 = 0;                // 阈值0
    float queue_treshold1 = 0;              // 阈值1
    float queue_treshold2 = 0;              // 阈值2
    std::string queue_baseline;             // 基线
    int queue_posintegration = 0;           // 积分位置
    std::string queue_calculated;           // 计算结果
    float queue_blancocal = 0;              // 空白标定值
    int queue_TrashTime1 = 0;               // 垃圾时间1
    int queue_AverageTime1 = 0;             // 平均时间1
    int queue_TrashTime2 = 0;               // 垃圾时间2
    int queue_AverageTime2 = 0;             // 平均时间2
    std::string queue_calibrationline;      // 标定线

    // 从 JSON 解析到结构体
    void from_json(const nlohmann::json &j)
    {
        j.at("id").get_to(id);
        j.at("queue_number").get_to(queue_number);
        j.at("queue_signalnumber").get_to(queue_signalnumber);
        j.at("queue_name").get_to(queue_name);
        j.at("queue_comment").get_to(queue_comment);
        j.at("queue_element").get_to(queue_element);
        j.at("queue_blanco").get_to(queue_blanco);
        j.at("queue_yield").get_to(queue_yield);
        j.at("queue_calibrationqueue").get_to(queue_calibrationqueue);
        j.at("queue_calibration_signalnumber").get_to(queue_calibration_signalnumber);
        j.at("queue_calibration_order").get_to(queue_calibration_order);
        j.at("queue_intercept").get_to(queue_intercept);
        j.at("queue_calibrationa").get_to(queue_calibrationa);
        j.at("queue_calibrationb").get_to(queue_calibrationb);
        j.at("queue_calibrationc").get_to(queue_calibrationc);
        j.at("queue_regression").get_to(queue_regression);
        j.at("queue_calibration_min").get_to(queue_calibration_min);
        j.at("queue_calibration_max").get_to(queue_calibration_max);
        j.at("queue_timewindow").get_to(queue_timewindow);
        j.at("queue_treshold0").get_to(queue_treshold0);
        j.at("queue_treshold1").get_to(queue_treshold1);
        j.at("queue_treshold2").get_to(queue_treshold2);
        j.at("queue_baseline").get_to(queue_baseline);
        j.at("queue_posintegration").get_to(queue_posintegration);
        j.at("queue_calculated").get_to(queue_calculated);
        j.at("queue_blancocal").get_to(queue_blancocal);
        j.at("queue_TrashTime1").get_to(queue_TrashTime1);
        j.at("queue_AverageTime1").get_to(queue_AverageTime1);
        j.at("queue_TrashTime2").get_to(queue_TrashTime2);
        j.at("queue_AverageTime2").get_to(queue_AverageTime2);
        j.at("queue_calibrationline").get_to(queue_calibrationline);
    }

    // 从结构体转换为 JSON
    void to_json(nlohmann::json &j) const
    {
        j["id"] = id;
        j["queue_number"] = queue_number;
        j["queue_signalnumber"] = queue_signalnumber;
        j["queue_name"] = queue_name;
        j["queue_comment"] = queue_comment;
        j["queue_element"] = queue_element;
        j["queue_blanco"] = queue_blanco;
        j["queue_yield"] = queue_yield;
        j["queue_calibrationqueue"] = queue_calibrationqueue;
        j["queue_calibration_signalnumber"] = queue_calibration_signalnumber;
        j["queue_calibration_order"] = queue_calibration_order;
        j["queue_intercept"] = queue_intercept;
        j["queue_calibrationa"] = queue_calibrationa;
        j["queue_calibrationb"] = queue_calibrationb;
        j["queue_calibrationc"] = queue_calibrationc;
        j["queue_regression"] = queue_regression;
        j["queue_calibration_min"] = queue_calibration_min;
        j["queue_calibration_max"] = queue_calibration_max;
        j["queue_timewindow"] = queue_timewindow;
        j["queue_treshold0"] = queue_treshold0;
        j["queue_treshold1"] = queue_treshold1;
        j["queue_treshold2"] = queue_treshold2;
        j["queue_baseline"] = queue_baseline;
        j["queue_posintegration"] = queue_posintegration;
        j["queue_calculated"] = queue_calculated;
        j["queue_blancocal"] = queue_blancocal;
        j["queue_TrashTime1"] = queue_TrashTime1;
        j["queue_AverageTime1"] = queue_AverageTime1;
        j["queue_TrashTime2"] = queue_TrashTime2;
        j["queue_AverageTime2"] = queue_AverageTime2;
        j["queue_calibrationline"] = queue_calibrationline;
    }
};

extern QueueList m_queueList;

#endif // HTTPD_QUEUELIST_H
