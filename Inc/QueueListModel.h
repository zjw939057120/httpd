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

    size_t list(std::vector<QueueListTable> &list);

    int add(QueueListTable &data);

    bool get(QueueListTable &data, size_t id);

    void remove(size_t id);

    void create();

public:
};


#endif //HTTPD_QUEUELISTMODEL_H
