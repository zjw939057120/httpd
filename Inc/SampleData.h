//
// Created by zjw93 on 2025/3/26.
//

#ifndef HTTPD_SAMPLEDATA_H
#define HTTPD_SAMPLEDATA_H

#include <cstdint>
#include <string>

struct SampleData {

};

struct SampleDataTable {
    int id;
    int sample_data_id;
    int queue_number;
    int sample_number;
    int sample_signalnumber;
    int sample_time;
    float sample_data;
};

extern SampleData m_sampleData;
#endif //HTTPD_SAMPLEDATA_H
