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

        // 根据类型渲染内容
        switch (item.type)
        {
        case 0: // 硫
            resp->json["data"]["method_temp"] = {{"炉温(℃)", item.method_temp0}};
            resp->json["data"]["method_pass"] = {{"系统压力", item.method_pass0}};
            resp->json["data"]["method_flow"] = {{"载气", item.method_flow0}, {"氧气", item.method_flow1}, {"臭氧", item.method_flow2}};
            resp->json["data"]["method_other"] = {{"采样时间", item.method_other0}, {"裂解时间", item.method_other1}, {"硫高压", item.method_other3}, {"氙灯高压", item.method_other4}};
            break;

        case 1: // 氮
            resp->json["data"]["method_temp"] = {{"炉温(℃)", item.method_temp0}, {"氮加热(℃)", item.method_temp1}};
            resp->json["data"]["method_pass"] = {{"系统压力", item.method_pass0}};
            resp->json["data"]["method_flow"] = {{"载气", item.method_flow0}, {"氧气", item.method_flow1}, {"臭氧", item.method_flow2}, {"裂解氧(%)", item.method_flow3}};
            resp->json["data"]["method_other"] = {{"采样时间", item.method_other0}, {"裂解时间", item.method_other1}, {"氮高压", item.method_other2}};
            break;

        case 2: // 氯
            resp->json["data"]["method_temp"] = {{"炉温(℃)", item.method_temp0}, {"电解池温度(℃)", item.method_temp4}};
            resp->json["data"]["method_pass"] = {{"系统压力", item.method_pass0}, {"氯压力", item.method_pass1}};
            resp->json["data"]["method_flow"] = {{"载气", item.method_flow0}, {"氧气", item.method_flow1}, {"臭氧", item.method_flow2}};
            resp->json["data"]["method_other"] = {{"采样时间", item.method_other0}, {"裂解时间", item.method_other1}};
            break;

        case 3: // 硫氮
            resp->json["data"]["method_temp"] = {{"炉温(℃)", item.method_temp0}, {"氮加热(℃)", item.method_temp1}, {"氮制冷(℃)", item.method_temp2}, {"催化剂温度(℃)", item.method_temp3}};
            resp->json["data"]["method_pass"] = {{"系统压力", item.method_pass0}};
            resp->json["data"]["method_flow"] = {{"载气", item.method_flow0}, {"氧气", item.method_flow1}, {"臭氧", item.method_flow2}, {"裂解氧(%)", item.method_flow3}};
            resp->json["data"]["method_other"] = {{"采样时间", item.method_other0}, {"裂解时间", item.method_other1}, {"氮高压", item.method_other2}, {"硫高压", item.method_other3}, {"氙灯高压", item.method_other4}};
            break;

        case 4: // CELL
            resp->json["data"]["method_temp"] = {{"电解池温度(℃)", item.method_temp4}};
            resp->json["data"]["method_pass"] = {};
            resp->json["data"]["method_flow"] = {};
            resp->json["data"]["method_other"] = {{"采样时间", item.method_other0}};
            break;

        case 5: // 待机
            resp->json["data"]["method_temp"] = {{"炉温(℃)", item.method_temp0}, {"氮加热(℃)", item.method_temp1}, {"氮制冷(℃)", item.method_temp2}, {"催化剂温度(℃)", item.method_temp3}, {"电解池温度(℃)", item.method_temp4}};
            resp->json["data"]["method_pass"] = {{"系统压力", item.method_pass0}, {"氯压力", item.method_pass1}};
            resp->json["data"]["method_flow"] = {{"载气", item.method_flow0}, {"氧气", item.method_flow1}, {"臭氧", item.method_flow2}, {"裂解氧(%)", item.method_flow3}};
            resp->json["data"]["method_other"] = {{"采样时间", item.method_other0}, {"裂解时间", item.method_other1}, {"氮高压", item.method_other2}, {"硫高压", item.method_other3}, {"氙灯高压", item.method_other4}};
            break;

        case 6: // 启动
            resp->json["data"]["method_temp"] = {{"炉温(℃)", item.method_temp0}, {"氮加热(℃)", item.method_temp1}, {"氮制冷(℃)", item.method_temp2}, {"催化剂温度(℃)", item.method_temp3}, {"电解池温度(℃)", item.method_temp4}};
            resp->json["data"]["method_pass"] = {{"系统压力", item.method_pass0}, {"氯压力", item.method_pass1}};
            resp->json["data"]["method_flow"] = {{"载气", item.method_flow0}, {"氧气", item.method_flow1}, {"臭氧", item.method_flow2}, {"裂解氧(%)", item.method_flow3}};
            resp->json["data"]["method_other"] = {{"采样时间", item.method_other0}, {"裂解时间", item.method_other1}, {"氮高压", item.method_other2}, {"硫高压", item.method_other3}, {"氙灯高压", item.method_other4}};
            break;

        default:
            break;
        }
    };

    Handler::response_json(req, resp, func);
    return 200;
}int MethodListHandler::get_filter(HttpRequest *req, HttpResponse *resp)
{
    auto func = [req, resp]
    {
        int id = std::stoi(req->GetParam("id"));
        MethodListTable item;
        Model::get(item, id);

        // 根据类型渲染内容
        switch (item.type)
        {
        case 0: // 硫
            resp->json["data"]["method_temp"] = {item.method_temp0};
            resp->json["data"]["method_pass"] = {item.method_pass0};
            resp->json["data"]["method_flow"] = {item.method_flow0, item.method_flow1, item.method_flow2};
            resp->json["data"]["method_other"] = {item.method_other0, item.method_other1, item.method_other3, item.method_other4};
            break;

        case 1: // 氮
            resp->json["data"]["method_temp"] = {item.method_temp0, item.method_temp1, item.method_temp2, item.method_temp3};
            resp->json["data"]["method_pass"] = {item.method_pass0};
            resp->json["data"]["method_flow"] = {item.method_flow0, item.method_flow1, item.method_flow2, item.method_flow3};
            resp->json["data"]["method_other"] = {item.method_other0, item.method_other1, item.method_other2};
            break;

        case 2: // 氯
            resp->json["data"]["method_temp"] = {item.method_temp0, item.method_temp4};
            resp->json["data"]["method_pass"] = {item.method_pass0, item.method_pass1};
            resp->json["data"]["method_flow"] = {item.method_flow0, item.method_flow1, item.method_flow2};
            resp->json["data"]["method_other"] = {item.method_other0, item.method_other1};
            break;

        case 3: // 硫氮
            resp->json["data"]["method_temp"] = {item.method_temp0, item.method_temp1, item.method_temp2, item.method_temp3};
            resp->json["data"]["method_pass"] = {item.method_pass0};
            resp->json["data"]["method_flow"] = {item.method_flow0, item.method_flow1, item.method_flow2, item.method_flow3};
            resp->json["data"]["method_other"] = {item.method_other0, item.method_other1, item.method_other2, item.method_other3, item.method_other4};
            break;

        case 4: // CELL
            resp->json["data"]["method_temp"] = {item.method_temp4};
            resp->json["data"]["method_pass"] = {};
            resp->json["data"]["method_flow"] = {};
            resp->json["data"]["method_other"] = {item.method_other0};
            break;

        case 5: // 待机
            resp->json["data"]["method_temp"] = {item.method_temp0, item.method_temp1, item.method_temp2, item.method_temp3, item.method_temp4};
            resp->json["data"]["method_pass"] = {item.method_pass0, item.method_pass1};
            resp->json["data"]["method_flow"] = {item.method_flow0, item.method_flow1, item.method_flow2, item.method_flow3};
            resp->json["data"]["method_other"] = {item.method_other0, item.method_other1, item.method_other2, item.method_other3, item.method_other4};
            break;

        case 6: // 启动
            resp->json["data"]["method_temp"] = {item.method_temp0, item.method_temp1, item.method_temp2, item.method_temp3, item.method_temp4};
            resp->json["data"]["method_pass"] = {item.method_pass0, item.method_pass1};
            resp->json["data"]["method_flow"] = {item.method_flow0, item.method_flow1, item.method_flow2, item.method_flow3};
            resp->json["data"]["method_other"] = {item.method_other0, item.method_other1, item.method_other2, item.method_other3, item.method_other4};
            break;

        default:
            break;
        }
    };

    Handler::response_json(req, resp, func);
    return 200;
}

int MethodListHandler::config(HttpRequest *req, HttpResponse *resp)
{
    auto func = [req, resp]
    {
        resp->json["data"]["type"] = {"单硫", "单氮", "单氯", "硫氮", "CELL", "待机", "启动"};
        resp->json["data"]["injector_type"] = {"AJ", "液体", "气体", "固体", "无"};
        resp->json["data"]["sample_type"] = {"液体", "气体", "固体"};
        resp->json["data"]["method_temp"] = {"炉温(℃)", "氮加热(℃)", "氮制冷(℃)", "催化剂温度(℃)", "电解池温度(℃)"};
        resp->json["data"]["method_pass"] = {"系统压力", "氯压力"};
        resp->json["data"]["method_flow"] = {"载气", "氧气", "臭氧", "裂解氧(%)"};
        resp->json["data"]["method_other"] = {"采样时间", "裂解时间", "氮高压", "硫高压", "氙灯高压"};
        resp->json["data"]["method_injector"] = {"清洗次数1", "清洗次数2", "置换次数", "提取速度", "排出速度", "进样速度", "注射器容积", "清洗体积", "容差体积", "返回速度", "总行程", "快进速度", "减速位", "燃烧位", "冷却温度", "加热温度", "扎入比例"};
    };

    Handler::response_json(req, resp, func);
    return 200;
}
