//
// Created by zjw93 on 2025/3/26.
//

#ifndef HTTPD_SAMPLEDATAMODEL_H
#define HTTPD_SAMPLEDATAMODEL_H

#include "model.h"
#include "SampleData.h"


// 全局变量 storage
static auto sampleDataStorage = make_storage("../etc/database.db",
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

class SampleDataModel {
public:
    SampleDataModel();

};


#endif //HTTPD_SAMPLEDATAMODEL_H
