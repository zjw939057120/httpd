//
// Created by zjw93 on 2025/3/26.
//

#include <iostream>
#include "SampleDataModel.h"

using namespace sqlite_orm;


SampleDataModel::SampleDataModel() {

}

// 全局变量 storage
static auto storage = make_storage("../etc/database.db",
                                   make_table("sample_data",
                                              make_column("id", &SampleDataTable::id,
                                                          primary_key().autoincrement()),
                                              make_column("sample_data_id",
                                                          &SampleDataTable::sample_data_id),
                                              make_column("queue_number",
                                                          &SampleDataTable::queue_number),
                                              make_column("sample_number",
                                                          &SampleDataTable::sample_number),
                                              make_column("sample_signalnumber",
                                                          &SampleDataTable::sample_signalnumber),
                                              make_column("sample_time",
                                                          &SampleDataTable::sample_time),
                                              make_column("sample_data",
                                                          &SampleDataTable::sample_data)
                                   )
);

size_t SampleDataModel::list(std::vector<SampleDataTable> &list) {
    list = storage.get_all<SampleDataTable>();
    return list.size();
}

int SampleDataModel::add(SampleDataTable &data) {
    return storage.insert(data);
}

bool SampleDataModel::get(SampleDataTable &data, size_t id) {
    try {
        data = storage.get<SampleDataTable>(id);
        return true;
    } catch (std::system_error e) {
        printf("SampleDataTable %zu %s\r\n", id, e.what());
        return false;
    } catch (...) {
        printf("SampleDataTable %zu unknown exeption\r\n", id);
        return false;
    }
}

void SampleDataModel::remove(size_t id) {
    storage.remove<SampleDataTable>(id);
}

void SampleDataModel::create() {
    storage.sync_schema();
}
