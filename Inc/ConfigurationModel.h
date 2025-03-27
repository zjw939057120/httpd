//
// Created by zjw93 on 2025/3/25.
//

#ifndef HTTPD_CONFIGURATIONMODEL_H
#define HTTPD_CONFIGURATIONMODEL_H

#include <sqlite_orm/sqlite_orm.h>
#include "Configuration.h"

class ConfigurationModel {
public:
    ConfigurationModel();

    size_t list(std::vector<ConfigurationTable> &list);

    int add(ConfigurationTable &data);

    bool get(ConfigurationTable &data, size_t id);

    void remove(size_t id);

    void create();

public:
};


#endif //HTTPD_CONFIGURATIONMODEL_H
