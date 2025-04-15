//
// Created by zjw93 on 2025/3/23.
//

#include "MethodListHandler.h"

#include "MethodList.h"
#include "handler.h"
#include <thread> // import std::thread
#include <chrono> // import std::chrono

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

int MethodListHandler::get_all(HttpRequest *req, HttpResponse *resp)
{
    auto func = [req, resp]
    {
        std::vector<MethodListTable> list;
        size_t size = Model::get_all(list);

        int seq = 0;
        for (auto &item : list)
        {
            item.to_json(resp->json["data"][seq]);
            seq++;
        }
    };
    Handler::response_json(req, resp, func);
    return 200;
}

int MethodListHandler::insert(HttpRequest *req, HttpResponse *resp)
{
    auto func = [req, resp]
    {
        MethodListTable item;
        item.from_json(req->GetJson());
        resp->json["data"] = Model::insert(item);
    };
    Handler::response_json(req, resp, func);
    return 200;
}

int MethodListHandler::update(HttpRequest *req, HttpResponse *resp)
{
    auto func = [req, resp]
    {
        MethodListTable item;
        item.from_json(req->GetJson());

        Model::update(item);
        resp->json["data"] = item.id;
    };

    Handler::response_json(req, resp, func);
    return 200;
}

int MethodListHandler::remove(HttpRequest *req, HttpResponse *resp)
{
    auto func = [req, resp]
    {
        int id = std::stoi(req->GetParam("id"));
        MethodListTable item;
        Model::remove(item, id);
        resp->json["data"] = id;
    };

    Handler::response_json(req, resp, func);
    return 200;
}

int MethodListHandler::get(HttpRequest *req, HttpResponse *resp)
{
    auto func = [req, resp]
    {
        int id = std::stoi(req->GetParam("id"));
        MethodListTable item;
        Model::get(item, id);
        item.to_json(resp->json["data"]);
    };

    Handler::response_json(req, resp, func);
    return 200;
}

int MethodListHandler::config(HttpRequest *req, HttpResponse *resp)
{
    auto func = [req, resp]
    {
        // 方法类型[0硫,1氮,2氯,3硫氮,4CELL,5待机,6启动]
        uint8_t i = 0;
        i = (uint8_t)MethodType::Sulfur;
        resp->json["data"]["type"][i]["method_temp"] = {TemperatureType::FurnaceTemp};
        resp->json["data"]["type"][i]["method_flow"] = {FlowType::CarrierGas, FlowType::Oxygen, FlowType::Ozone};
        resp->json["data"]["type"][i]["method_pass"] = {PressureType::SystemPressure};
        resp->json["data"]["type"][i]["method_other"] = {OtherParameterType::SamplingTime, OtherParameterType::CrackingTime, OtherParameterType::NitrogenHighPressure, OtherParameterType::XenonLampHighPressure};
        i = (uint8_t)MethodType::Nitrogen;
        resp->json["data"]["type"][i]["method_temp"] = {1, 2, 3};
        resp->json["data"]["type"][i]["method_flow"] = {1, 2, 3};
        resp->json["data"]["type"][i]["method_pass"] = {1, 2, 3};
        resp->json["data"]["type"][i]["method_other"] = {1, 2, 3};
        i = (uint8_t)MethodType::Chlorine;
        resp->json["data"]["type"][i]["method_temp"] = {1, 2, 3};
        resp->json["data"]["type"][i]["method_flow"] = {1, 2, 3};
        resp->json["data"]["type"][i]["method_pass"] = {1, 2, 3};
        resp->json["data"]["type"][i]["method_other"] = {1, 2, 3};
        i = (uint8_t)MethodType::SulfurNitrogen;
        resp->json["data"]["type"][i]["method_temp"] = {1, 2, 3};
        resp->json["data"]["type"][i]["method_flow"] = {1, 2, 3};
        resp->json["data"]["type"][i]["method_pass"] = {1, 2, 3};
        resp->json["data"]["type"][i]["method_other"] = {1, 2, 3};
        i = (uint8_t)MethodType::CELL;
        resp->json["data"]["type"][i]["method_temp"] = {1, 2, 3};
        resp->json["data"]["type"][i]["method_flow"] = {1, 2, 3};
        resp->json["data"]["type"][i]["method_pass"] = {1, 2, 3};
        resp->json["data"]["type"][i]["method_other"] = {1, 2, 3};
        i = (uint8_t)MethodType::Standby;
        resp->json["data"]["type"][i]["method_temp"] = {1, 2, 3};
        resp->json["data"]["type"][i]["method_flow"] = {1, 2, 3};
        resp->json["data"]["type"][i]["method_pass"] = {1, 2, 3};
        resp->json["data"]["type"][i]["method_other"] = {1, 2, 3};
        i = (uint8_t)MethodType::Startup;
        resp->json["data"]["type"][i]["method_temp"] = {1, 2, 3};
        resp->json["data"]["type"][i]["method_flow"] = {1, 2, 3};
        resp->json["data"]["type"][i]["method_pass"] = {1, 2, 3};
        resp->json["data"]["type"][i]["method_other"] = {1, 2, 3};
    };

    Handler::response_json(req, resp, func);
    return 200;
}