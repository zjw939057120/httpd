//
// Created by zjw93 on 2025/3/26.
//

#ifndef HTTPD_SYSTEM_H
#define HTTPD_SYSTEM_H

#include <cstdint>
#include <string>
#include "hv/json.hpp"

struct System {
    bool debug; //Debug模式
    int port;
};

struct SystemTable {
    int id;

    // 从 JSON 解析到结构体
    void from_json(const nlohmann::json &j) {
        j.at("id").get_to(id);
    }
//
//    // 从结构体转换为 JSON
//    void to_json(const SystemTable &t, nlohmann::json &j) {
//        j["id"] = t.id;
//    }
};

extern System m_system;

#endif //HTTPD_SYSTEM_H
