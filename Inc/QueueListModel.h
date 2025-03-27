//
// Created by zjw93 on 2025/3/25.
//

#ifndef HTTPD_QUEUELISTMODEL_H
#define HTTPD_QUEUELISTMODEL_H

#include <sqlite_orm/sqlite_orm.h>
#include "QueueList.h"

class QueueListModel {
public:
    QueueListModel();

    size_t get_all(std::vector<QueueListTable> &list);

    int insert(QueueListTable &data);

    bool get(QueueListTable &data, size_t id);

    void remove(size_t id);

public:
};


#endif //HTTPD_QUEUELISTMODEL_H
