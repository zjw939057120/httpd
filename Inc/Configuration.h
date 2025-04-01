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
    int id;
    int config_parameternumber;
    std::string config_name;
    std::string config_parametername;
    float config_floatvalue;
    int config_integervalue;
    std::string config_stringvalue;
    int config_booleanvalue;


// 从 JSON 解析到结构体
    void from_json(const nlohmann::json &j) {
        j.at("id").get_to(id);
    }
//
//// 从结构体转换为 JSON
//    void to_json(const ConfigurationTable &t, nlohmann::json &j) {
//        j["id"] = t.id;
//    }
};

extern Configuration m_configuration;

#endif //HTTPD_CONFIGURATION_H
