//
// Created by zjw93 on 2025/3/26.
//

#ifndef HTTPD_CONFIGURATION_H
#define HTTPD_CONFIGURATION_H

#include <cstdint>
#include <string>
#include "hv/json.hpp"


struct Configuration {

};

struct ConfigurationTable {
    int id = 0;
    int config_parameternumber = 0;
    std::string config_name;
    std::string config_parametername;
    float config_floatvalue = 0;
    int config_integervalue = 0;
    std::string config_stringvalue;
    int config_booleanvalue = 0;

    // 从 JSON 解析到结构体
    void from_json(const nlohmann::json &j) {
        j.at("id").get_to(id);
        j.at("config_parameternumber").get_to(config_parameternumber);
        j.at("config_name").get_to(config_name);
        j.at("config_parametername").get_to(config_parametername);
        j.at("config_floatvalue").get_to(config_floatvalue);
        j.at("config_integervalue").get_to(config_integervalue);
        j.at("config_stringvalue").get_to(config_stringvalue);
        j.at("config_booleanvalue").get_to(config_booleanvalue);
    }

    // 从结构体转换为 JSON
    void to_json(nlohmann::json &j) const {
        j["id"] = id;
        j["config_parameternumber"] = config_parameternumber;
        j["config_name"] = config_name;
        j["config_parametername"] = config_parametername;
        j["config_floatvalue"] = config_floatvalue;
        j["config_integervalue"] = config_integervalue;
        j["config_stringvalue"] = config_stringvalue;
        j["config_booleanvalue"] = config_booleanvalue;
    }
};

extern Configuration m_configuration;

#endif //HTTPD_CONFIGURATION_H
