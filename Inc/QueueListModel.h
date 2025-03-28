//
// Created by zjw93 on 2025/3/25.
//

#ifndef HTTPD_QUEUELISTMODEL_H
#define HTTPD_QUEUELISTMODEL_H

#include "model.h"
#include "QueueList.h"

// 全局变量 storage
static auto queueListsStorage = make_storage("../etc/database.db",
                                   make_table("queue_list",
                                              make_column("id", &QueueListTable::id,
                                                          primary_key().autoincrement()),
                                              make_column("queue_number",
                                                          &QueueListTable::queue_number),
                                              make_column("queue_signalnumber",
                                                          &QueueListTable::queue_signalnumber),
                                              make_column("queue_name",
                                                          &QueueListTable::queue_name),
                                              make_column("queue_comment",
                                                          &QueueListTable::queue_comment),
                                              make_column("queue_element",
                                                          &QueueListTable::queue_element),
                                              make_column("queue_blanco",
                                                          &QueueListTable::queue_blanco),
                                              make_column("queue_yield",
                                                          &QueueListTable::queue_yield),
                                              make_column("queue_calibrationqueue",
                                                          &QueueListTable::queue_calibrationqueue),
                                              make_column("queue_calibration_signalnumber",
                                                          &QueueListTable::queue_calibration_signalnumber),
                                              make_column("queue_calibration_order",
                                                          &QueueListTable::queue_calibration_order),
                                              make_column("queue_intercept",
                                                          &QueueListTable::queue_intercept),
                                              make_column("queue_calibrationa",
                                                          &QueueListTable::queue_calibrationa),
                                              make_column("queue_calibrationb",
                                                          &QueueListTable::queue_calibrationb),
                                              make_column("queue_calibrationc",
                                                          &QueueListTable::queue_calibrationc),
                                              make_column("queue_regression",
                                                          &QueueListTable::queue_regression),
                                              make_column("queue_calibration_min",
                                                          &QueueListTable::queue_calibration_min),
                                              make_column("queue_calibration_max",
                                                          &QueueListTable::queue_calibration_max),
                                              make_column("queue_timewindow",
                                                          &QueueListTable::queue_timewindow),
                                              make_column("queue_treshold0",
                                                          &QueueListTable::queue_treshold0),
                                              make_column("queue_treshold1",
                                                          &QueueListTable::queue_treshold1),
                                              make_column("queue_treshold2",
                                                          &QueueListTable::queue_treshold2),
                                              make_column("queue_baseline",
                                                          &QueueListTable::queue_baseline),
                                              make_column("queue_posintegration",
                                                          &QueueListTable::queue_posintegration),
                                              make_column("queue_calculated",
                                                          &QueueListTable::queue_calculated),
                                              make_column("queue_blancocal",
                                                          &QueueListTable::queue_blancocal),
                                              make_column("queue_TrashTime1",
                                                          &QueueListTable::queue_TrashTime1),
                                              make_column("queue_AverageTime1",
                                                          &QueueListTable::queue_AverageTime1),
                                              make_column("queue_TrashTime2",
                                                          &QueueListTable::queue_TrashTime2),
                                              make_column("queue_AverageTime2",
                                                          &QueueListTable::queue_AverageTime2),
                                              make_column("queue_calibrationline",
                                                          &QueueListTable::queue_calibrationline)
                                   )
);

class QueueListModel {
public:
    QueueListModel();

};


#endif //HTTPD_QUEUELISTMODEL_H
