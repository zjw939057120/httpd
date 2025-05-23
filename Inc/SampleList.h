//
// Created by zjw93 on 2025/3/26.
//

#ifndef HTTPD_SAMPLELIST_H
#define HTTPD_SAMPLELIST_H

#include <cstdint>
#include <string>
#include "hv/json.hpp"

struct SampleList
{
};

struct SampleListTable
{
    int id = 0;                          // 样本列表ID
    int queue_number = 0;                // 队列编号
    int sample_number = 0;               // 样本编号
    int sample_signalnumber = 0;         // 样本信号编号
    std::string sample_name;             // 样本名称
    float sample_area = 0;               // 样本面积
    float sample_amount = 0;             // 样本量
    std::string sample_amountunit;       // 样本量单位
    float sample_startamount = 0;        // 样本起始量
    std::string sample_startamount_unit; // 样本起始量单位
    int sample_place = 0;                // 样本位置
    float sample_dilution = 0;           // 样本稀释倍数
    float sample_density = 0;            // 样本密度
    float sample_molweight = 0;          // 样本分子量
    float sample_tolerance = 0;          // 样本容差
    std::string sample_type;             // 样本类型
    std::string sample_method;           // 样本方法
    float sample_result = 0;             // 样本结果
    std::string sample_date;             // 样本日期
    std::string sample_comment;          // 样本备注
    std::string sample_log;              // 样本日志
    std::string sample_analyst_name;     // 样本分析员名称
    float sample_totalcomponent = 0;     // 样本总成分
    float sample_cal_concentration = 0;  // 样本标定浓度
    float sample_concentration = 0;      // 样本浓度
    std::string sample_conc_unit;        // 样本浓度单位
    int sample_beginpeak = 0;            // 样本起始峰
    float sample_beginpeak_value = 0;    // 样本起始峰值
    int sample_endpeak = 0;              // 样本结束峰
    float sample_endpeak_value = 0;      // 样本结束峰值
    int sample_id = 0;                   // 样本ID
    float sample_mean = 0;               // 样本均值
    float sample_vc = 0;                 // 样本变异系数
    float sample_sd = 0;                 // 样本标准差
    int sample_flag = 0;                 // 样本标志
    std::string sample_temperature;      // 样本温度
    float sample_pressure = 0;           // 样本压力
    std::string sample_calibration_line; // 样本标定线
    int sample_loops = 0;                // 样本循环次数

    // 从 JSON 解析到结构体
    void from_json(const nlohmann::json &j)
    {
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

    // 从结构体转换为 JSON
    void to_json(nlohmann::json &j) const
    {
        j["id"] = id;
        j["queue_number"] = queue_number;
        j["sample_number"] = sample_number;
        j["sample_signalnumber"] = sample_signalnumber;
        j["sample_name"] = sample_name;
        j["sample_area"] = sample_area;
        j["sample_amount"] = sample_amount;
        j["sample_amountunit"] = sample_amountunit;
        j["sample_startamount"] = sample_startamount;
        j["sample_startamount_unit"] = sample_startamount_unit;
        j["sample_place"] = sample_place;
        j["sample_dilution"] = sample_dilution;
        j["sample_density"] = sample_density;
        j["sample_molweight"] = sample_molweight;
        j["sample_tolerance"] = sample_tolerance;
        j["sample_type"] = sample_type;
        j["sample_method"] = sample_method;
        j["sample_result"] = sample_result;
        j["sample_date"] = sample_date;
        j["sample_comment"] = sample_comment;
        j["sample_log"] = sample_log;
        j["sample_analyst_name"] = sample_analyst_name;
        j["sample_totalcomponent"] = sample_totalcomponent;
        j["sample_cal_concentration"] = sample_cal_concentration;
        j["sample_concentration"] = sample_concentration;
        j["sample_conc_unit"] = sample_conc_unit;
        j["sample_beginpeak"] = sample_beginpeak;
        j["sample_beginpeak_value"] = sample_beginpeak_value;
        j["sample_endpeak"] = sample_endpeak;
        j["sample_endpeak_value"] = sample_endpeak_value;
        j["sample_id"] = sample_id;
        j["sample_mean"] = sample_mean;
        j["sample_vc"] = sample_vc;
        j["sample_sd"] = sample_sd;
        j["sample_flag"] = sample_flag;
        j["sample_temperature"] = sample_temperature;
        j["sample_pressure"] = sample_pressure;
        j["sample_calibration_line"] = sample_calibration_line;
        j["sample_loops"] = sample_loops;
    }
};

extern SampleList m_sampleList;

#endif // HTTPD_SAMPLELIST_H
