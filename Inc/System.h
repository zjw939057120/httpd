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
};

extern System m_system;

#endif //HTTPD_SYSTEM_H
