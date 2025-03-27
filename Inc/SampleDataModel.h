//
// Created by zjw93 on 2025/3/26.
//

#ifndef HTTPD_SAMPLEDATAMODEL_H
#define HTTPD_SAMPLEDATAMODEL_H

#include <sqlite_orm/sqlite_orm.h>
#include "SampleData.h"

class SampleDataModel {
public:
    SampleDataModel();

    size_t list(std::vector<SampleDataTable> &list);

    int add(SampleDataTable &data);

    bool get(SampleDataTable &data, size_t id);

    void remove(size_t id);

    void create();

public:
};


#endif //HTTPD_SAMPLEDATAMODEL_H
