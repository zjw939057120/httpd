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
};

extern SampleList m_sampleList;

#endif //HTTPD_SAMPLELIST_H
