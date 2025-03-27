//
// Created by zjw93 on 2025/3/25.
//

#include <iostream>
#include "MethodListModel.h"

using namespace sqlite_orm;

MethodListModel::MethodListModel() {

}

// 全局变量 storage
static auto storage = make_storage("../etc/database.db",
                                   make_table("method_list",
                                              make_column("id", &MethodListTable::id,
                                                          primary_key().autoincrement()),
                                              make_column("method_number",
                                                          &MethodListTable::method_number),
                                              make_column("method_step",
                                                          &MethodListTable::method_step),
                                              make_column("method_stage",
                                                          &MethodListTable::method_stage),
                                              make_column("method_stepname",
                                                          &MethodListTable::method_stepname),
                                              make_column("method_timestep",
                                                          &MethodListTable::method_timestep),
                                              make_column("method_actionname",
                                                          &MethodListTable::method_actionname),
                                              make_column("method_actionnumber",
                                                          &MethodListTable::method_actionnumber),
                                              make_column("method_parametername1",
                                                          &MethodListTable::method_parametername1),
                                              make_column("method_parametername2",
                                                          &MethodListTable::method_parametername2),
                                              make_column("method_parametername3",
                                                          &MethodListTable::method_parametername3),
                                              make_column("method_parametername4",
                                                          &MethodListTable::method_parametername4),
                                              make_column("method_parametername5",
                                                          &MethodListTable::method_parametername5),
                                              make_column("method_parametername6",
                                                          &MethodListTable::method_parametername6),
                                              make_column("method_parametername7",
                                                          &MethodListTable::method_parametername7),
                                              make_column("method_parametername8",
                                                          &MethodListTable::method_parametername8),
                                              make_column("method_parametername9",
                                                          &MethodListTable::method_parametername9),
                                              make_column("method_parametername10",
                                                          &MethodListTable::method_parametername10),
                                              make_column("method_parametertype",
                                                          &MethodListTable::method_parametertype),
                                              make_column("method_parameter1",
                                                          &MethodListTable::method_parameter1),
                                              make_column("method_parameter2",
                                                          &MethodListTable::method_parameter2),
                                              make_column("method_parameter3",
                                                          &MethodListTable::method_parameter1),
                                              make_column("method_parameter4",
                                                          &MethodListTable::method_parameter4),
                                              make_column("method_parameter5",
                                                          &MethodListTable::method_parameter5),
                                              make_column("method_parameter6",
                                                          &MethodListTable::method_parameter6),
                                              make_column("method_parameter7",
                                                          &MethodListTable::method_parameter7),
                                              make_column("method_parameter8",
                                                          &MethodListTable::method_parameter8),
                                              make_column("method_parameter9",
                                                          &MethodListTable::method_parameter9),
                                              make_column("method_parameter10",
                                                          &MethodListTable::method_parameter10),
                                              make_column("method_config",
                                                          &MethodListTable::method_config)
                                   )
);

size_t MethodListModel::list(std::vector<MethodListTable> &list) {
    list = storage.get_all<MethodListTable>();
    return list.size();
}

int MethodListModel::add(MethodListTable &data) {
    return storage.insert(data);
}

bool MethodListModel::get(MethodListTable &data, size_t id) {
    try {
        data = storage.get<MethodListTable>(id);
        return true;
    } catch (std::system_error e) {
        printf("MethodListTable %zu %s\r\n", id, e.what());
        return false;
    } catch (...) {
        printf("MethodListTable %zu unknown exeption\r\n", id);
        return false;
    }
}

void MethodListModel::remove(size_t id) {
    storage.remove<MethodListTable>(id);
}

void MethodListModel::create() {
    storage.sync_schema();
}
