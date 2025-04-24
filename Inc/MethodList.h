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

struct MethodListTable
{
    int id = 0;                  // 方法ID
    std::string method_name;            // 方法名称
    int method_type = 0;                // 方法类型 [0: 硫, 1: 氮, 2: 氯, 3: 硫氮, 4: CELL, 5: 待机, 6: 启动]
    int injector_type = 0;       // 进样器类型 [0: AJ, 1: 液体, 2: 气体, 3: 固体, 4: 无]
    int sample_type = 0;         // 样本类型 [0: 液体, 1: 气体, 2: 固体]
    float method_temp0 = 0;      // 温度参数0 [炉温(℃)]
    float method_temp1 = 0;      // 温度参数1 [氮加热(℃)]
    float method_temp2 = 0;      // 温度参数2 [氮制冷(℃)]
    float method_temp3 = 0;      // 温度参数3 [催化剂温度(℃)]
    float method_temp4 = 0;      // 温度参数4 [电解池温度(℃)]
    float method_temp5 = 0;      // 温度参数5 [备用]
    float method_flow0 = 0;      // 流量参数0 [载气]
    float method_flow1 = 0;      // 流量参数1 [氧气]
    float method_flow2 = 0;      // 流量参数2 [臭氧]
    float method_flow3 = 0;      // 流量参数3 [裂解氧(%)]
    float method_flow4 = 0;      // 流量参数4 [备用]
    float method_flow5 = 0;      // 流量参数5 [备用]
    float method_pass0 = 0;      // 压力参数0 [系统压力]
    float method_pass1 = 0;      // 压力参数1 [氯压力]
    float method_pass2 = 0;      // 压力参数2 [备用]
    float method_pass3 = 0;      // 压力参数3 [备用]
    float method_pass4 = 0;      // 压力参数4 [备用]
    float method_pass5 = 0;      // 压力参数5 [备用]
    float method_other0 = 0;     // 其他参数0 [采样时间]
    float method_other1 = 0;     // 其他参数1 [裂解时间]
    float method_other2 = 0;     // 其他参数2 [氮高压]
    float method_other3 = 0;     // 其他参数3 [硫高压]
    float method_other4 = 0;     // 其他参数4 [氙灯高压]
    float method_other5 = 0;     // 其他参数5 [备用]
    float method_injector0 = 0;  // 进样器参数0 [清洗次数1]
    float method_injector1 = 0;  // 进样器参数1 [清洗次数2]
    float method_injector2 = 0;  // 进样器参数2 [置换次数]
    float method_injector3 = 0;  // 进样器参数3 [提取速度]
    float method_injector4 = 0;  // 进样器参数4 [排出速度]
    float method_injector5 = 0;  // 进样器参数5 [进样速度]
    float method_injector6 = 0;  // 进样器参数6 [注射器容积]
    float method_injector7 = 0;  // 进样器参数7 [清洗体积]
    float method_injector8 = 0;  // 进样器参数8 [容差体积]
    float method_injector9 = 0;  // 进样器参数9 [返回速度]
    float method_injector10 = 0; // 进样器参数10 [总行程]
    float method_injector11 = 0; // 进样器参数11 [快进速度]
    float method_injector12 = 0; // 进样器参数12 [减速位]
    float method_injector13 = 0; // 进样器参数13 [燃烧位]
    float method_injector14 = 0; // 进样器参数14 [冷却温度]
    float method_injector15 = 0; // 进样器参数15 [加热温度]
    float method_injector16 = 0; // 进样器参数16 [扎入比例]

    // 从 JSON 解析到结构体
    void from_json(const nlohmann::json &j)
    {
        j.at("id").get_to(id);
        j.at("method_name").get_to(method_name);
        j.at("method_type").get_to(method_type);
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
        j["method_name"] = method_name;
        j["method_type"] = method_type;
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
