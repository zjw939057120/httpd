//
// Created by zjw93 on 2025/3/25.
//

#ifndef HTTPD_METHODLISTMODEL_H
#define HTTPD_METHODLISTMODEL_H

#include <sqlite_orm/sqlite_orm.h>
#include "MethodList.h"

class MethodListModel {
public:
    MethodListModel();

    size_t list(std::vector<MethodListTable> &list);

    int add(MethodListTable &data);

    bool get(MethodListTable &data, size_t id);

    void remove(size_t id);

    void create();

public:
};


#endif //HTTPD_METHODLISTMODEL_H
