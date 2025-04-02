//
// Created by zjw93 on 2025/3/26.
//

#ifndef HTTPD_SAMPLEDATA_H
#define HTTPD_SAMPLEDATA_H

#include <cstdint>
#include <string>
#include "hv/json.hpp"

struct SampleData {

};

struct SampleDataTable {
    int id = 0;
    int sample_data_id = 0;
    int queue_number = 0;
    int sample_number = 0;
    int sample_signalnumber = 0;
    int sample_time = 0;
    float sample_data = 0;

    // 从 JSON 解析到结构体
    void from_json(const nlohmann::json &j) {
        j.at("id").get_to(id);
        j.at("sample_data_id").get_to(sample_data_id);
        j.at("queue_number").get_to(queue_number);
        j.at("sample_number").get_to(sample_number);
        j.at("sample_signalnumber").get_to(sample_signalnumber);
        j.at("sample_time").get_to(sample_time);
        j.at("sample_data").get_to(sample_data);
    }

    // 从结构体转换为 JSON
    void to_json(nlohmann::json &j) const {
        j["id"] = id;
        j["sample_data_id"] = sample_data_id;
        j["queue_number"] = queue_number;
        j["sample_number"] = sample_number;
        j["sample_signalnumber"] = sample_signalnumber;
        j["sample_time"] = sample_time;
        j["sample_data"] = sample_data;
    }
};

extern SampleData m_sampleData;
#endif //HTTPD_SAMPLEDATA_H
