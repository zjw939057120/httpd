//
// Created by zjw93 on 2025/3/26.
//

#ifndef HTTPD_METHODLIST_H
#define HTTPD_METHODLIST_H

#include <cstdint>
#include <string>
#include "hv/json.hpp"

struct MethodList {

};

struct MethodListTable {
    int id = 0;
    int method_number = 0;
    int method_step = 0;
    std::string method_name;
    int method_stage = 0;
    std::string method_stepname;
    int method_timestep = 0;
    std::string method_actionname;
    int method_actionnumber = 0;
    std::string method_parametername1;
    std::string method_parametername2;
    std::string method_parametername3;
    std::string method_parametername4;
    std::string method_parametername5;
    std::string method_parametername6;
    std::string method_parametername7;
    std::string method_parametername8;
    std::string method_parametername9;
    std::string method_parametername10;
    int method_parametertype = 0;
    std::string method_parameter1;
    std::string method_parameter2;
    std::string method_parameter3;
    std::string method_parameter4;
    std::string method_parameter5;
    std::string method_parameter6;
    std::string method_parameter7;
    std::string method_parameter8;
    std::string method_parameter9;
    std::string method_parameter10;
    std::string method_config;

    // 从 JSON 解析到结构体
    void from_json(const nlohmann::json &j) {
        j.at("id").get_to(id);
        j.at("method_number").get_to(method_number);
        j.at("method_step").get_to(method_step);
        j.at("method_name").get_to(method_name);
        j.at("method_stage").get_to(method_stage);
        j.at("method_stepname").get_to(method_stepname);
        j.at("method_timestep").get_to(method_timestep);
        j.at("method_actionname").get_to(method_actionname);
        j.at("method_actionnumber").get_to(method_actionnumber);
        j.at("method_parametername1").get_to(method_parametername1);
        j.at("method_parametername2").get_to(method_parametername2);
        j.at("method_parametername3").get_to(method_parametername3);
        j.at("method_parametername4").get_to(method_parametername4);
        j.at("method_parametername5").get_to(method_parametername5);
        j.at("method_parametername6").get_to(method_parametername6);
        j.at("method_parametername7").get_to(method_parametername7);
        j.at("method_parametername8").get_to(method_parametername8);
        j.at("method_parametername9").get_to(method_parametername9);
        j.at("method_parametername10").get_to(method_parametername10);
        j.at("method_parametertype").get_to(method_parametertype);
        j.at("method_parameter1").get_to(method_parameter1);
        j.at("method_parameter2").get_to(method_parameter2);
        j.at("method_parameter3").get_to(method_parameter3);
        j.at("method_parameter4").get_to(method_parameter4);
        j.at("method_parameter5").get_to(method_parameter5);
        j.at("method_parameter6").get_to(method_parameter6);
        j.at("method_parameter7").get_to(method_parameter7);
        j.at("method_parameter8").get_to(method_parameter8);
        j.at("method_parameter9").get_to(method_parameter9);
        j.at("method_parameter10").get_to(method_parameter10);
        j.at("method_config").get_to(method_config);
    }

    // 从结构体转换为 JSON
    void to_json(nlohmann::json &j) const {
        j["id"] = id;
        j["method_number"] = method_number;
        j["method_step"] = method_step;
        j["method_name"] = method_name;
        j["method_stage"] = method_stage;
        j["method_stepname"] = method_stepname;
        j["method_timestep"] = method_timestep;
        j["method_actionname"] = method_actionname;
        j["method_actionnumber"] = method_actionnumber;
        j["method_parametername1"] = method_parametername1;
        j["method_parametername2"] = method_parametername2;
        j["method_parametername3"] = method_parametername3;
        j["method_parametername4"] = method_parametername4;
        j["method_parametername5"] = method_parametername5;
        j["method_parametername6"] = method_parametername6;
        j["method_parametername7"] = method_parametername7;
        j["method_parametername8"] = method_parametername8;
        j["method_parametername9"] = method_parametername9;
        j["method_parametername10"] = method_parametername10;
        j["method_parametertype"] = method_parametertype;
        j["method_parameter1"] = method_parameter1;
        j["method_parameter2"] = method_parameter2;
        j["method_parameter3"] = method_parameter3;
        j["method_parameter4"] = method_parameter4;
        j["method_parameter5"] = method_parameter5;
        j["method_parameter6"] = method_parameter6;
        j["method_parameter7"] = method_parameter7;
        j["method_parameter8"] = method_parameter8;
        j["method_parameter9"] = method_parameter9;
        j["method_parameter10"] = method_parameter10;
        j["method_config"] = method_config;
    }
};

extern MethodList g_methodList;

#endif //HTTPD_METHODLIST_H
