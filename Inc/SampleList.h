//
// Created by zjw93 on 2025/3/26.
//

#ifndef HTTPD_SAMPLELIST_H
#define HTTPD_SAMPLELIST_H

#include <cstdint>
#include <string>
#include "hv/json.hpp"

struct SampleList {

};

struct SampleListTable {
    int id;
    int queue_number;
    int sample_number;
    int sample_signalnumber;
    std::string sample_name;
    float sample_area;
    float sample_amount;
    std::string sample_amountunit;
    float sample_startamount;
    std::string sample_startamount_unit;
    int sample_place;
    float sample_dilution;
    float sample_density;
    float sample_molweight;
    float sample_tolerance;
    std::string sample_type;
    std::string sample_method;
    float sample_result;
    std::string sample_date;
    std::string sample_comment;
    std::string sample_log;
    std::string sample_analyst_name;
    float sample_totalcomponent;
    float sample_cal_concentration;
    float sample_concentration;
    std::string sample_conc_unit;
    int sample_beginpeak;
    float sample_beginpeak_value;
    int sample_endpeak;
    float sample_endpeak_value;
    int sample_id;
    float sample_mean;
    float sample_vc;
    float sample_sd;
    int sample_flag;
    std::string sample_temperature;
    float sample_pressure;
    std::string sample_calibration_line;
    int sample_loops;

    // 从 JSON 解析到结构体
    void from_json(const nlohmann::json &j) {
        j.at("id").get_to(id);
        j.at("queue_number").get_to(queue_number);
        j.at("sample_number").get_to(sample_number);
        j.at("sample_signalnumber").get_to(sample_signalnumber);
        j.at("sample_name").get_to(sample_name);
        j.at("sample_area").get_to(sample_area);
        j.at("sample_amount").get_to(sample_amount);
        j.at("sample_amountunit").get_to(sample_amountunit);
        j.at("sample_startamount").get_to(sample_startamount);
        j.at("sample_startamount_unit").get_to(sample_startamount_unit);
        j.at("sample_place").get_to(sample_place);
        j.at("sample_dilution").get_to(sample_dilution);
        j.at("sample_density").get_to(sample_density);
        j.at("sample_molweight").get_to(sample_molweight);
        j.at("sample_tolerance").get_to(sample_tolerance);
        j.at("sample_type").get_to(sample_type);
        j.at("sample_method").get_to(sample_method);
        j.at("sample_result").get_to(sample_result);
        j.at("sample_date").get_to(sample_date);
        j.at("sample_comment").get_to(sample_comment);
        j.at("sample_log").get_to(sample_log);
        j.at("sample_analyst_name").get_to(sample_analyst_name);
        j.at("sample_totalcomponent").get_to(sample_totalcomponent);
        j.at("sample_cal_concentration").get_to(sample_cal_concentration);
        j.at("sample_concentration").get_to(sample_concentration);
        j.at("sample_conc_unit").get_to(sample_conc_unit);
        j.at("sample_beginpeak").get_to(sample_beginpeak);
        j.at("sample_beginpeak_value").get_to(sample_beginpeak_value);
        j.at("sample_endpeak").get_to(sample_endpeak);
        j.at("sample_endpeak_value").get_to(sample_endpeak_value);
        j.at("sample_id").get_to(sample_id);
        j.at("sample_mean").get_to(sample_mean);
        j.at("sample_vc").get_to(sample_vc);
        j.at("sample_sd").get_to(sample_sd);
        j.at("sample_flag").get_to(sample_flag);
        j.at("sample_temperature").get_to(sample_temperature);
        j.at("sample_pressure").get_to(sample_pressure);
        j.at("sample_calibration_line").get_to(sample_calibration_line);
        j.at("sample_loops").get_to(sample_loops);
    }
//
//    // 从结构体转换为 JSON
//    void to_json(const SampleListTable &t, nlohmann::json &j) {
//        j.at("id").get_to(id);
//        j.at("queue_number").get_to(queue_number);
//        j.at("sample_number").get_to(sample_number);
//        j.at("sample_signalnumber").get_to(sample_signalnumber);
//        j.at("sample_name").get_to(sample_name);
//        j.at("sample_area").get_to(sample_area);
//        j.at("sample_amount").get_to(sample_amount);
//        j.at("sample_amountunit").get_to(sample_amountunit);
//        j.at("sample_startamount").get_to(sample_startamount);
//        j.at("sample_startamount_unit").get_to(sample_startamount_unit);
//        j.at("sample_place").get_to(sample_place);
//        j.at("sample_dilution").get_to(sample_dilution);
//        j.at("sample_density").get_to(sample_density);
//        j.at("sample_molweight").get_to(sample_molweight);
//        j.at("sample_tolerance").get_to(sample_tolerance);
//        j.at("sample_type").get_to(sample_type);
//        j.at("sample_method").get_to(sample_method);
//        j.at("sample_result").get_to(sample_result);
//        j.at("sample_date").get_to(sample_date);
//        j.at("sample_comment").get_to(sample_comment);
//        j.at("sample_log").get_to(sample_log);
//        j.at("sample_analyst_name").get_to(sample_analyst_name);
//        j.at("sample_totalcomponent").get_to(sample_totalcomponent);
//        j.at("sample_cal_concentration").get_to(sample_cal_concentration);
//        j.at("sample_concentration").get_to(sample_concentration);
//        j.at("sample_conc_unit").get_to(sample_conc_unit);
//        j.at("sample_beginpeak").get_to(sample_beginpeak);
//        j.at("sample_beginpeak_value").get_to(sample_beginpeak_value);
//        j.at("sample_endpeak").get_to(sample_endpeak);
//        j.at("sample_endpeak_value").get_to(sample_endpeak_value);
//        j.at("sample_id").get_to(sample_id);
//        j.at("sample_mean").get_to(sample_mean);
//        j.at("sample_vc").get_to(sample_vc);
//        j.at("sample_sd").get_to(sample_sd);
//        j.at("sample_flag").get_to(sample_flag);
//        j.at("sample_temperature").get_to(sample_temperature);
//        j.at("sample_pressure").get_to(sample_pressure);
//        j.at("sample_calibration_line").get_to(sample_calibration_line);
//        j.at("sample_loops").get_to(sample_loops);
//    }
};

extern SampleList m_sampleList;

#endif //HTTPD_SAMPLELIST_H
