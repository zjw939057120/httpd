//
// Created by zjw93 on 2025/3/26.
//

#ifndef HTTPD_METHODLIST_H
#define HTTPD_METHODLIST_H

#include <cstdint>
#include <string>
#include "hv/json.hpp"

struct MethodList
{
};

// 方法类型
enum class MethodType
{
    Sulfur = 0,         // 硫
    Nitrogen = 1,       // 氮
    Chlorine = 2,       // 氯
    SulfurNitrogen = 3, // 硫氮
    CELL = 4,           // CELL
    Standby = 5,        // 待机
    Startup = 6         // 启动
};

// 进样器类型
enum class InjectorType
{
    AJ = 0,     // AJ
    Liquid = 1, // 液体
    Gas = 2,    // 气体
    Solid = 3,  // 固体
    None = 4    // 无
};

// 样本类型
enum class SampleType
{
    Liquid = 0, // 液体
    Gas = 1,    // 气体
    Solid = 2   // 固体
};

/// 温度类型枚举
enum class TemperatureType
{
    FurnaceTemp = 0,         // 炉温(℃)
    NitrogenHeating = 1,     // 氮加热(℃)
    NitrogenCooling = 2,     // 氮制冷(℃)
    CatalystTemp = 3,        // 催化剂温度(℃)
    ElectrolyticCellTemp = 4 // 电解池温度(℃)
};

enum class FlowType
{
    CarrierGas = 0,    // 载气
    Oxygen = 1,        // 氧气
    Ozone = 2,         // 臭氧
    CrackingOxygen = 3 // 裂解氧(%)
};

enum class PressureType
{
    SystemPressure = 0,  // 系统压力
    ChlorinePressure = 1 // 氯压力
};

// 其他参数枚举
enum class OtherParameterType
{
    SamplingTime = 0,         // 采样时间
    CrackingTime = 1,         // 裂解时间
    NitrogenHighPressure = 2, // 氮高压
    SulfurHighPressure = 3,   // 硫高压
    XenonLampHighPressure = 4 // 氙灯高压
};

// 进样器参数枚举
enum class InjectorParameterType
{
    CleaningTimes1 = 0,        // 清洗次数1
    CleaningTimes2 = 1,        // 清洗次数2
    ReplacementTimes = 2,      // 置换次数
    ExtractionSpeed = 3,       // 提取速度
    DischargeSpeed = 4,        // 排出速度
    InjectionSpeed = 5,        // 进样速度
    SyringeVolume = 6,         // 注射器容积
    CleaningVolume = 7,        // 清洗体积
    ToleranceVolume = 8,       // 容差体积
    ReturnSpeed = 9,           // 返回速度
    TotalStroke = 10,          // 总行程
    FastForwardSpeed = 11,     // 快进速度
    DecelerationPosition = 12, // 减速位
    CombustionPosition = 13,   // 燃烧位
    CoolingTemperature = 14,   // 冷却温度
    HeatingTemperature = 15,   // 加热温度
    PenetrationRatio = 16      // 扎入比例
};

struct MethodListTable
{
    int id = 0;
    std::string name;      // 方法名称
    int type = 0;          // 方法类型[0硫,1氮,2氯,3硫氮,4CELL,5待机,6启动]
    int injector_type = 0; // 进样器类型[0AJ,1液体,2气体,3固体,4无]
    int sample_type = 0;   // 样本类型[0液体,1气体,2固体]
    float method_temp0 = 0;
    float method_temp1 = 0; // 温度[0炉温(℃),1氮加热(℃),2氮制冷(℃),3催化剂温度(℃),4电解池温度(℃)]
    float method_temp2 = 0;
    float method_temp3 = 0;
    float method_temp4 = 0;
    float method_temp5 = 0;
    float method_flow0 = 0;
    float method_flow1 = 0; // 流量[0载气,1氧气,2臭氧,3裂解氧(%)]
    float method_flow2 = 0;
    float method_flow3 = 0;
    float method_flow4 = 0;
    float method_flow5 = 0;
    float method_pass0 = 0;
    float method_pass1 = 0; // 压力[0系统压力,1氯压力]
    float method_pass2 = 0;
    float method_pass3 = 0;
    float method_pass4 = 0;
    float method_pass5 = 0;
    float method_other0 = 0;
    float method_other1 = 0; // 其他参数[0采样时间,1裂解时间,2氮高压,3硫高压,4氙灯高压]
    float method_other2 = 0;
    float method_other3 = 0;
    float method_other4 = 0;
    float method_other5 = 0;
    float method_injector0 = 0;
    float method_injector1 = 0; // 进样器参数 [0清洗次数1,清洗次数2,置换次数,3提取速度,4排出速度,5进样速度,6注射器容积,7清洗体积,8容差体积,9返回速度,10总行程,11快进速度,12减速位,13燃烧位,14冷却温度,15加热温度,16扎入比例]
    float method_injector2 = 0;
    float method_injector3 = 0;
    float method_injector4 = 0;
    float method_injector5 = 0;
    float method_injector6 = 0;
    float method_injector7 = 0;
    float method_injector8 = 0;
    float method_injector9 = 0;
    float method_injector10 = 0;
    float method_injector11 = 0;
    float method_injector12 = 0;
    float method_injector13 = 0;
    float method_injector14 = 0;
    float method_injector15 = 0;
    float method_injector16 = 0;

    // 从 JSON 解析到结构体
    void from_json(const nlohmann::json &j)
    {
        j.at("id").get_to(id);
        j.at("name").get_to(name);
        j.at("type").get_to(type);
        j.at("injector_type").get_to(injector_type);
        j.at("sample_type").get_to(sample_type);
        j.at("method_temp0").get_to(method_temp0);
        j.at("method_temp1").get_to(method_temp1);
        j.at("method_temp2").get_to(method_temp2);
        j.at("method_temp3").get_to(method_temp3);
        j.at("method_temp4").get_to(method_temp4);
        j.at("method_temp5").get_to(method_temp5);
        j.at("method_flow0").get_to(method_flow0);
        j.at("method_flow1").get_to(method_flow1);
        j.at("method_flow2").get_to(method_flow2);
        j.at("method_flow3").get_to(method_flow3);
        j.at("method_flow4").get_to(method_flow4);
        j.at("method_flow5").get_to(method_flow5);
        j.at("method_pass0").get_to(method_pass0);
        j.at("method_pass1").get_to(method_pass1);
        j.at("method_pass2").get_to(method_pass2);
        j.at("method_pass3").get_to(method_pass3);
        j.at("method_pass4").get_to(method_pass4);
        j.at("method_pass5").get_to(method_pass5);
        j.at("method_other0").get_to(method_other0);
        j.at("method_other1").get_to(method_other1);
        j.at("method_other2").get_to(method_other2);
        j.at("method_other3").get_to(method_other3);
        j.at("method_other4").get_to(method_other4);
        j.at("method_other5").get_to(method_other5);
        j.at("method_injector0").get_to(method_injector0);
        j.at("method_injector1").get_to(method_injector1);
        j.at("method_injector2").get_to(method_injector2);
        j.at("method_injector3").get_to(method_injector3);
        j.at("method_injector4").get_to(method_injector4);
        j.at("method_injector5").get_to(method_injector5);
        j.at("method_injector6").get_to(method_injector6);
        j.at("method_injector7").get_to(method_injector7);
        j.at("method_injector8").get_to(method_injector8);
        j.at("method_injector9").get_to(method_injector9);
        j.at("method_injector10").get_to(method_injector10);
        j.at("method_injector11").get_to(method_injector11);
        j.at("method_injector12").get_to(method_injector12);
        j.at("method_injector13").get_to(method_injector13);
        j.at("method_injector14").get_to(method_injector14);
        j.at("method_injector15").get_to(method_injector15);
        j.at("method_injector16").get_to(method_injector16);
    }

    // 从结构体转换为 JSON
    void to_json(nlohmann::json &j) const
    {
        j["id"] = id;
        j["name"] = name;
        j["type"] = type;
        j["injector_type"] = injector_type;
        j["sample_type"] = sample_type;
        j["method_temp0"] = method_temp0;
        j["method_temp1"] = method_temp1;
        j["method_temp2"] = method_temp2;
        j["method_temp3"] = method_temp3;
        j["method_temp4"] = method_temp4;
        j["method_temp5"] = method_temp5;
        j["method_flow0"] = method_flow0;
        j["method_flow1"] = method_flow1;
        j["method_flow2"] = method_flow2;
        j["method_flow3"] = method_flow3;
        j["method_flow4"] = method_flow4;
        j["method_flow5"] = method_flow5;
        j["method_pass0"] = method_pass0;
        j["method_pass1"] = method_pass1;
        j["method_pass2"] = method_pass2;
        j["method_pass3"] = method_pass3;
        j["method_pass4"] = method_pass4;
        j["method_pass5"] = method_pass5;
        j["method_other0"] = method_other0;
        j["method_other1"] = method_other1;
        j["method_other2"] = method_other2;
        j["method_other3"] = method_other3;
        j["method_other4"] = method_other4;
        j["method_other5"] = method_other5;
        j["method_injector0"] = method_injector0;
        j["method_injector1"] = method_injector1;
        j["method_injector2"] = method_injector2;
        j["method_injector3"] = method_injector3;
        j["method_injector4"] = method_injector4;
        j["method_injector5"] = method_injector5;
        j["method_injector6"] = method_injector6;
        j["method_injector7"] = method_injector7;
        j["method_injector8"] = method_injector8;
        j["method_injector9"] = method_injector9;
        j["method_injector10"] = method_injector10;
        j["method_injector11"] = method_injector11;
        j["method_injector12"] = method_injector12;
        j["method_injector13"] = method_injector13;
        j["method_injector14"] = method_injector14;
        j["method_injector15"] = method_injector15;
        j["method_injector16"] = method_injector16;
    }
};

extern MethodList g_methodList;

#endif // HTTPD_METHODLIST_H
