//
// Created by zjw93 on 2025/3/26.
//

#ifndef HTTPD_SAMPLELISTMODEL_H
#define HTTPD_SAMPLELISTMODEL_H

#include <sqlite_orm/sqlite_orm.h>
#include "SampleList.h"

class SampleListModel {
public:
    SampleListModel();

    size_t get_all(std::vector<SampleListTable> &list);

    int insert(SampleListTable &data);

    bool get(SampleListTable &data, size_t id);

    void remove(size_t id);

public:
};


#endif //HTTPD_SAMPLELISTMODEL_H
