//
// Created by zjw93 on 2025/3/26.
//

#ifndef HTTPD_SAMPLELISTMODEL_H
#define HTTPD_SAMPLELISTMODEL_H

#include "model.h"
#include "SampleList.h"

// 全局变量 storage
static auto sampleListStorage = make_storage("../etc/database.db",
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

class SampleListModel {
public:
    SampleListModel();

};


#endif //HTTPD_SAMPLELISTMODEL_H
