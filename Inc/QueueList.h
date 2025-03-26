//
// Created by zjw93 on 2025/3/26.
//

#ifndef HTTPD_QUEUELIST_H
#define HTTPD_QUEUELIST_H

#include <cstdint>
#include <string>

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
};

extern QueueList m_queueList;

#endif //HTTPD_QUEUELIST_H
