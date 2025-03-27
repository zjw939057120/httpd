//
// Created by zjw93 on 2025/3/26.
//

#include <iostream>
#include "SampleListModel.h"

using namespace sqlite_orm;


SampleListModel::SampleListModel() {

}

// 全局变量 storage
static auto storage = make_storage("../etc/database.db",
                                   make_table("sample_list",
                                              make_column("id", &SampleListTable::id,
                                                          primary_key().autoincrement()),
                                              make_column("queue_number",
                                                          &SampleListTable::queue_number),
                                              make_column("sample_number",
                                                          &SampleListTable::sample_number),
                                              make_column("sample_signalnumber",
                                                          &SampleListTable::sample_signalnumber),
                                              make_column("sample_name",
                                                          &SampleListTable::sample_name),
                                              make_column("sample_area",
                                                          &SampleListTable::sample_area),
                                              make_column("sample_amount",
                                                          &SampleListTable::sample_amount),
                                              make_column("sample_amountunit",
                                                          &SampleListTable::sample_amountunit),
                                              make_column("sample_startamount",
                                                          &SampleListTable::sample_startamount),
                                              make_column("sample_startamount_unit",
                                                          &SampleListTable::sample_startamount_unit),
                                              make_column("sample_place",
                                                          &SampleListTable::sample_place),
                                              make_column("sample_dilution",
                                                          &SampleListTable::sample_dilution),
                                              make_column("sample_density",
                                                          &SampleListTable::sample_density),
                                              make_column("sample_molweight",
                                                          &SampleListTable::sample_molweight),
                                              make_column("sample_tolerance",
                                                          &SampleListTable::sample_tolerance),
                                              make_column("sample_type",
                                                          &SampleListTable::sample_type),
                                              make_column("sample_method",
                                                          &SampleListTable::sample_method),
                                              make_column("sample_result",
                                                          &SampleListTable::sample_result),
                                              make_column("sample_date",
                                                          &SampleListTable::sample_date),
                                              make_column("sample_comment",
                                                          &SampleListTable::sample_comment),
                                              make_column("sample_log",
                                                          &SampleListTable::sample_log),
                                              make_column("sample_analyst_name",
                                                          &SampleListTable::sample_analyst_name),
                                              make_column("sample_totalcomponent",
                                                          &SampleListTable::sample_totalcomponent),
                                              make_column("sample_cal_concentration",
                                                          &SampleListTable::sample_cal_concentration),
                                              make_column("sample_concentration",
                                                          &SampleListTable::sample_concentration),
                                              make_column("sample_conc_unit",
                                                          &SampleListTable::sample_conc_unit),
                                              make_column("sample_beginpeak",
                                                          &SampleListTable::sample_beginpeak),
                                              make_column("sample_beginpeak_value",
                                                          &SampleListTable::sample_beginpeak_value),
                                              make_column("sample_endpeak",
                                                          &SampleListTable::sample_endpeak),
                                              make_column("sample_endpeak_value",
                                                          &SampleListTable::sample_endpeak_value),
                                              make_column("sample_id",
                                                          &SampleListTable::sample_id),
                                              make_column("sample_mean",
                                                          &SampleListTable::sample_mean),
                                              make_column("sample_vc",
                                                          &SampleListTable::sample_vc),
                                              make_column("sample_sd",
                                                          &SampleListTable::sample_sd),
                                              make_column("sample_flag",
                                                          &SampleListTable::sample_flag),
                                              make_column("sample_temperature",
                                                          &SampleListTable::sample_temperature),
                                              make_column("sample_pressure",
                                                          &SampleListTable::sample_pressure),
                                              make_column("sample_calibration_line",
                                                          &SampleListTable::sample_calibration_line),
                                              make_column("sample_loops",
                                                          &SampleListTable::sample_loops)

                                   )
);

size_t SampleListModel::list(std::vector<SampleListTable> &list) {
    list = storage.get_all<SampleListTable>();
    return list.size();
}

int SampleListModel::add(SampleListTable &data) {
    return storage.insert(data);
}

bool SampleListModel::get(SampleListTable &data, size_t id) {
    try {
        data = storage.get<SampleListTable>(id);
        return true;
    } catch (std::system_error e) {
        printf("SampleListTable %zu %s\r\n", id, e.what());
        return false;
    } catch (...) {
        printf("SampleListTable %zu unknown exeption\r\n", id);
        return false;
    }
}

void SampleListModel::remove(size_t id) {
    storage.remove<SampleListTable>(id);
}

void SampleListModel::create() {
    storage.sync_schema();
}
