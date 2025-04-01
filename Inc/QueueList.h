//
// Created by zjw93 on 2025/3/26.
//

#ifndef HTTPD_QUEUELIST_H
#define HTTPD_QUEUELIST_H

#include <cstdint>
#include <string>
#include "hv/json.hpp"

struct QueueList {

};

struct QueueListTable {
    int id;
    int queue_number;
    int queue_signalnumber;
    std::string queue_name;
    std::string queue_comment;
    int queue_element;
    float queue_blanco;
    float queue_yield;
    int queue_calibrationqueue;
    int queue_calibration_signalnumber;
    int queue_calibration_order;
    int queue_intercept;
    float queue_calibrationa;
    float queue_calibrationb;
    float queue_calibrationc;
    float queue_regression;
    int queue_calibration_min;
    int queue_calibration_max;
    int queue_timewindow;
    int queue_treshold0;
    float queue_treshold1;
    float queue_treshold2;
    std::string queue_baseline;
    int queue_posintegration;
    std::string queue_calculated;
    float queue_blancocal;
    int queue_TrashTime1;
    int queue_AverageTime1;
    int queue_TrashTime2;
    int queue_AverageTime2;
    std::string queue_calibrationline;

    // 从 JSON 解析到结构体
    void from_json(const nlohmann::json &j) {
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
//
//    // 从结构体转换为 JSON
//    void to_json(const QueueListTable &t, nlohmann::json &j) {
//        j["id"] = t.id;
//    }
};

extern QueueList m_queueList;

#endif //HTTPD_QUEUELIST_H
