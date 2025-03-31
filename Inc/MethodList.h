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
    int id;
    int method_number;
    int method_step;
    std::string method_name;
    int method_stage;
    std::string method_stepname;
    int method_timestep;
    std::string method_actionname;
    int method_actionnumber;
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
    int method_parametertype;
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
};

extern MethodList g_methodList;

#endif //HTTPD_METHODLIST_H
