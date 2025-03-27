//
// Created by zjw93 on 2025/3/25.
//

#include "ConfigurationModel.h"
#include <Configuration.h>
#include <iostream>

using namespace sqlite_orm;

ConfigurationModel::ConfigurationModel() {

}

// 全局变量 storage
static auto storage = make_storage("../etc/database.db",
                                   make_table("configuration",
                                              make_column("id", &ConfigurationTable::id,
                                                          primary_key().autoincrement()),
                                              make_column("config_parameternumber",
                                                          &ConfigurationTable::config_parameternumber),
                                              make_column("config_parametername",
                                                          &ConfigurationTable::config_parametername),
                                              make_column("config_floatvalue",
                                                          &ConfigurationTable::config_floatvalue),
                                              make_column("config_integervalue",
                                                          &ConfigurationTable::config_integervalue),
                                              make_column("config_stringvalue",
                                                          &ConfigurationTable::config_stringvalue),
                                              make_column("config_booleanvalue",
                                                          &ConfigurationTable::config_booleanvalue)
                                   )
);

size_t ConfigurationModel::list(std::vector<ConfigurationTable> &list) {
    list = storage.get_all<ConfigurationTable>();
    return list.size();
}

int ConfigurationModel::add(ConfigurationTable &data) {
    return storage.insert(data);
}

bool ConfigurationModel::get(ConfigurationTable &data, size_t id) {
    try {
        data = storage.get<ConfigurationTable>(id);
        return true;
    } catch (std::system_error e) {
        printf("CalibrationModel %zu %s\r\n", id, e.what());
        return false;
    } catch (...) {
        printf("CalibrationModel %zu unknown exeption\r\n", id);
        return false;
    }
}

void ConfigurationModel::remove(size_t id) {
    storage.remove<ConfigurationTable>(id);
}

void ConfigurationModel::create() {
    storage.sync_schema();
}
