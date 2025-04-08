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


int SystemHandler::menu(HttpRequest *req, HttpResponse *resp) {
    resp->content_type = APPLICATION_JSON;

    uint8_t i = 0;
    uint8_t j = 0;

    i = 0;
    j = 0;
    resp->json["data"][i]["title"] = "主页";
    resp->json["data"][i]["icon"] = "layui-icon-home";
    resp->json["data"][i]["list"][j]["title"] = "控制台";
    resp->json["data"][i]["list"][j]["jump"] = "/";
    j++;
    resp->json["data"][i]["list"][j]["title"] = "主页一";
    resp->json["data"][i]["list"][j]["jump"] = "home/homepage1";
    j++;
    resp->json["data"][i]["list"][j]["title"] = "主页二";
    resp->json["data"][i]["list"][j]["jump"] = "home/homepage2";

    i++;
    j = 0;
    resp->json["data"][i]["name"] = "component";
    resp->json["data"][i]["title"] = "组件";
    resp->json["data"][i]["icon"] = "layui-icon-component";
    resp->json["data"][i]["list"][j]["name"] = "button";
    resp->json["data"][i]["list"][j]["title"] = "按钮";
    j++;
    resp->json["data"][i]["list"][j]["name"] = "nav";
    resp->json["data"][i]["list"][j]["title"] = "导航";
    j++;
    resp->json["data"][i]["list"][j]["name"] = "tabs";
    resp->json["data"][i]["list"][j]["title"] = "选项卡";
    j++;
    resp->json["data"][i]["list"][j]["name"] = "progress";
    resp->json["data"][i]["list"][j]["title"] = "进度条";
    j++;
    resp->json["data"][i]["list"][j]["name"] = "panel";
    resp->json["data"][i]["list"][j]["title"] = "面板";
    j++;
    resp->json["data"][i]["list"][j]["name"] = "badge";
    resp->json["data"][i]["list"][j]["title"] = "徽章";
    j++;
    resp->json["data"][i]["list"][j]["name"] = "timeline";
    resp->json["data"][i]["list"][j]["title"] = "时间线";
    j++;
    resp->json["data"][i]["list"][j]["name"] = "anim";
    resp->json["data"][i]["list"][j]["title"] = "动画";
    j++;
    resp->json["data"][i]["list"][j]["name"] = "auxiliar";
    resp->json["data"][i]["list"][j]["title"] = "辅助";

    return 200;
}

int SystemHandler::test(HttpRequest *req, HttpResponse *resp) {
    resp->content_type = APPLICATION_JSON;

    try {
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

    } catch (const nlohmann::json::parse_error &e) {
        std::cerr << "Parse error: " << e.what() << std::endl;
        Handler::response_status(resp, 0, e.what());
    } catch (const nlohmann::json::out_of_range &e) {
        std::cerr << "Out of range error: " << e.what() << std::endl;
        Handler::response_status(resp, 0, e.what());
    } catch (const nlohmann::json::type_error &e) {
        std::cerr << "Type error: " << e.what() << std::endl;
        Handler::response_status(resp, 0, e.what());
    } catch (std::system_error e) {
        std::cout << e.what() << std::endl;
        Handler::response_status(resp, 0, e.what());
    }catch (...) {
        std::cout << "unknown exeption" << std::endl;
        Handler::response_status(resp, 0, "unknown exeption");
    }

    return 200;
}

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
        int id = atoi(req->GetParam("id").c_str());
        CalibrationTable item;
        Model::remove(item, id);
        resp->json["data"] = id;
    };

    Handler::response_json(req, resp, func);
    return 200;
}

int SystemHandler::get(HttpRequest *req, HttpResponse *resp) {
    auto func = [req, resp] {
        int id = atoi(req->GetParam("id").c_str());
        CalibrationTable item;
        Model::get(item, id);
        item.to_json(resp->json["data"]);
    };

    Handler::response_json(req, resp, func);
    return 200;
}
