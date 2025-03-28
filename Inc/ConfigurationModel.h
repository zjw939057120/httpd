//
// Created by zjw93 on 2025/3/25.
//

#ifndef HTTPD_CONFIGURATIONMODEL_H
#define HTTPD_CONFIGURATIONMODEL_H

#include "model.h"
#include "Configuration.h"

// 全局变量 storage
static auto configurationStorage = make_storage("../etc/database.db",
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

class ConfigurationModel {
public:
    ConfigurationModel();

};


#endif //HTTPD_CONFIGURATIONMODEL_H
