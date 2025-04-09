//
// Created by zjw93 on 2025/3/23.
//

#include "SystemHandler.h"

#include "handler.h"
#include "System.h"
#include <thread>   // import std::thread
#include <chrono>   // import std::chrono

#include "hbase.h"
#include "htime.h"
#include "hfile.h"
#include "hstring.h"
#include "EventLoop.h" // import setTimeout, setInterval

#include <sqlite_orm/sqlite_orm.h>
#include <Utils.h>
#include "CalibrationModel.h"
#include "ConfigurationModel.h"
#include "MethodListModel.h"
#include "QueueListModel.h"
#include "SampleDataModel.h"
#include "SampleListModel.h"
#include <fstream>

int SystemHandler::menu(HttpRequest *req, HttpResponse *resp)
{
    auto func = [req, resp]
    {
        uint8_t i = 0;
        uint8_t j = 0;
        // 加載演示功能菜单
#ifdef DEBUG_MODE
        {
            std::string filePath = "../html/start/json/menu.js";
            std::ifstream file(filePath);
            if (!file.is_open())
            {
                throw std::runtime_error("Failed to open file: " + filePath);
            }

            // 解析 JSON 文件
            nlohmann::json jsonData;
            file >> jsonData; // 将文件内容解析为 JSON 对象
            resp->json = jsonData;
            file.close();
            i = resp->json["data"].size();
        }
#endif
        
        resp->json["data"][i]["name"] = "status";
        resp->json["data"][i]["title"] = "系统状态";
        resp->json["data"][i]["icon"] = "layui-icon-component";
        resp->json["data"][i]["jump"] = "/device/status";
        i++;
        resp->json["data"][i]["name"] = "method";
        resp->json["data"][i]["title"] = "方法管理";
        resp->json["data"][i]["icon"] = "layui-icon-template";
        resp->json["data"][i]["jump"] = "/device/method";
        i++;
        resp->json["data"][i]["name"] = "queue";
        resp->json["data"][i]["title"] = "队列管理";
        resp->json["data"][i]["icon"] = "layui-icon-app";
        resp->json["data"][i]["jump"] = "/device/queue";
        i++;
        resp->json["data"][i]["name"] = "sample";
        resp->json["data"][i]["title"] = "评估结果";
        resp->json["data"][i]["icon"] = "layui-icon-senior";
        resp->json["data"][i]["jump"] = "/device/sample";
        i++;
        resp->json["data"][i]["name"] = "analyze";
        resp->json["data"][i]["title"] = "智能分析";
        resp->json["data"][i]["icon"] = "layui-icon-user";
        resp->json["data"][i]["jump"] = "/device/analyze";
        i++;
        resp->json["data"][i]["name"] = "config";
        resp->json["data"][i]["title"] = "系统配置";
        resp->json["data"][i]["icon"] = "layui-icon-set";
        resp->json["data"][i]["jump"] = "/device/config";
    };

    Handler::response_json(req, resp, func);
    return 200;
};

int SystemHandler::test(HttpRequest *req, HttpResponse *resp) {
    auto func = [req, resp] {
        Model::sync_schema();

        CalibrationTable data;
        Model::insert(data);
        if (Model::get(data, 10))
            std::cout << "ID:" << data.id << ", calibration_line:" << data.calibration_line << ", calibration_A:"
                      << data.calibration_A << std::endl;

        // 查询 CalibrationTable 表的所有数据
        std::vector<CalibrationTable> list;
        size_t len = Model::get_all(list);

        for (int i = 0; i < len; ++i) {
            resp->json["data"][i] = list[i].id;
            std::cout << "ID:" << list[i].id << ", calibration_line:" << list[i].calibration_line << ", calibration_A:"
                      << list[i].calibration_A << std::endl;
        }
    };

    Handler::response_json(req, resp, func);
    return 200;
};

int SystemHandler::get_all(HttpRequest *req, HttpResponse *resp) {
    auto func = [req, resp] {
        std::vector<CalibrationTable> list;
        size_t size = Model::get_all(list);

        int seq = 0;
        for (auto &item:list) {
            item.to_json(resp->json["data"][seq]);
            seq++;
        }
    };
    Handler::response_json(req, resp, func);
    return 200;
}

int SystemHandler::insert(HttpRequest *req, HttpResponse *resp) {
    auto func = [req, resp] {
        CalibrationTable item;
        item.from_json(req->GetJson());
        resp->json["data"] = Model::insert(item);
    };
    Handler::response_json(req, resp, func);
    return 200;
}

int SystemHandler::update(HttpRequest *req, HttpResponse *resp) {
    auto func = [req, resp] {
        CalibrationTable item;
        item.from_json(req->GetJson());

        Model::update(item);
        resp->json["data"] = item.id;
    };

    Handler::response_json(req, resp, func);
    return 200;
}

int SystemHandler::remove(HttpRequest *req, HttpResponse *resp) {
    auto func = [req, resp] {
        int id = std::stoi(req->GetParam("id"));
        CalibrationTable item;
        Model::remove(item, id);
        resp->json["data"] = id;
    };

    Handler::response_json(req, resp, func);
    return 200;
}

int SystemHandler::get(HttpRequest *req, HttpResponse *resp) {
    auto func = [req, resp] {
        int id = std::stoi(req->GetParam("id"));
        CalibrationTable item;
        Model::get(item, id);
        item.to_json(resp->json["data"]);
    };

    Handler::response_json(req, resp, func);
    return 200;
}
