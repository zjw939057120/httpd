//
// Created by zjw93 on 2025/3/26.
//

#ifndef HTTPD_SAMPLEDATAMODE_H
#define HTTPD_SAMPLEDATAMODE_H

#include <sqlite_orm/sqlite_orm.h>
#include "SampleData.h"

class SampleDataMode {
public:
    SampleDataMode();

    size_t get_all(std::vector<SampleDataTable> &list);

    int insert(SampleDataTable &data);

    bool get(SampleDataTable &data, size_t id);

    void remove(size_t id);

public:
};


#endif //HTTPD_SAMPLEDATAMODE_H
