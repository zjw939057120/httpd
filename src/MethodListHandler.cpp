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

        if (size == 0)
        {
            resp->json["data"] = {};
            return;
        }
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
        time_t now = std::time(NULL);
        MethodListTable item;
        item.from_json(req->GetJson());
        item.method_name += std::to_string(now); // 添加ID到名称后面
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
        int method_type = std::stoi(req->GetParam("method_type", "-1"));
        int injector_type = std::stoi(req->GetParam("injector_type", "-1"));
        int sample_type = std::stoi(req->GetParam("sample_type", "-1"));
        MethodListTable item;
        Model::get(item, id);

        method_type = method_type == -1 ? item.method_type : method_type;         // method_type
        injector_type = injector_type == -1 ? item.injector_type : injector_type; // injector_type
        sample_type = sample_type == -1 ? item.sample_type : sample_type;         // sample_type

        resp->json["data"]["method_temp"] = {{}, {}, {}, {}, {}};
        resp->json["data"]["method_pass"] = {{}, {}, {}, {}, {}};
        resp->json["data"]["method_flow"] = {{}, {}, {}, {}, {}};
        resp->json["data"]["method_other"] = {{}, {}, {}, {}, {}};
        resp->json["data"]["method_injector"] = {{}, {}, {}, {}, {}, {}, {}, {}, {}, {}};
        // 根据类型渲染内容
        switch (method_type)
        {
        case 0: // 硫
            resp->json["data"]["method_temp"][0] = {0, "炉温(℃)", item.method_temp0};
            resp->json["data"]["method_pass"][0] = {0, "系统压力", item.method_pass0};
            resp->json["data"]["method_flow"][0] = {0, "载气", item.method_flow0};
            resp->json["data"]["method_flow"][1] = {1, "氧气", item.method_flow1};
            resp->json["data"]["method_flow"][2] = {2, "臭氧", item.method_flow2};
            resp->json["data"]["method_other"][0] = {0, "采样时间", item.method_other0};
            resp->json["data"]["method_other"][1] = {1, "裂解时间", item.method_other1};
            resp->json["data"]["method_other"][2] = {3, "硫高压", item.method_other3};
            resp->json["data"]["method_other"][3] = {4, "氙灯高压", item.method_other4};
            break;

        case 1: // 氮
            resp->json["data"]["method_temp"][0] = {0, "炉温(℃)", item.method_temp0};
            resp->json["data"]["method_temp"][1] = {1, "氮加热(℃)", item.method_temp1};
            resp->json["data"]["method_pass"][0] = {0, "系统压力", item.method_pass0};
            resp->json["data"]["method_flow"][0] = {0, "载气", item.method_flow0};
            resp->json["data"]["method_flow"][1] = {1, "氧气", item.method_flow1};
            resp->json["data"]["method_flow"][2] = {2, "臭氧", item.method_flow2};
            resp->json["data"]["method_flow"][3] = {3, "裂解氧(%)", item.method_flow3};
            resp->json["data"]["method_other"][0] = {0, "采样时间", item.method_other0};
            resp->json["data"]["method_other"][1] = {1, "裂解时间", item.method_other1};
            resp->json["data"]["method_other"][2] = {2, "氮高压", item.method_other2};
            break;

        case 2: // 氯
            resp->json["data"]["method_temp"][0] = {0, "炉温(℃)", item.method_temp0};
            resp->json["data"]["method_temp"][1] = {4, "电解池温度(℃)", item.method_temp4};
            resp->json["data"]["method_pass"][0] = {0, "系统压力", item.method_pass0};
            resp->json["data"]["method_pass"][1] = {1, "氯压力", item.method_pass1};
            resp->json["data"]["method_flow"][0] = {0, "载气", item.method_flow0};
            resp->json["data"]["method_flow"][1] = {1, "氧气", item.method_flow1};
            resp->json["data"]["method_flow"][2] = {2, "臭氧", item.method_flow2};
            resp->json["data"]["method_other"][0] = {0, "采样时间", item.method_other0};
            resp->json["data"]["method_other"][1] = {1, "裂解时间", item.method_other1};
            break;

        case 3: // 硫氮
            resp->json["data"]["method_temp"][0] = {0, "炉温(℃)", item.method_temp0};
            resp->json["data"]["method_temp"][1] = {1, "氮加热(℃)", item.method_temp1};
            resp->json["data"]["method_temp"][2] = {2, "氮制冷(℃)", item.method_temp2};
            resp->json["data"]["method_temp"][3] = {3, "催化剂温度(℃)", item.method_temp3};
            resp->json["data"]["method_pass"][0] = {0, "系统压力", item.method_pass0};
            resp->json["data"]["method_flow"][0] = {0, "载气", item.method_flow0};
            resp->json["data"]["method_flow"][1] = {1, "氧气", item.method_flow1};
            resp->json["data"]["method_flow"][2] = {2, "臭氧", item.method_flow2};
            resp->json["data"]["method_flow"][3] = {3, "裂解氧(%)", item.method_flow3};
            resp->json["data"]["method_other"][0] = {0, "采样时间", item.method_other0};
            resp->json["data"]["method_other"][1] = {1, "裂解时间", item.method_other1};
            resp->json["data"]["method_other"][2] = {2, "氮高压", item.method_other2};
            resp->json["data"]["method_other"][3] = {3, "硫高压", item.method_other3};
            resp->json["data"]["method_other"][4] = {4, "氙灯高压", item.method_other4};
            break;

        case 4: // CELL
            resp->json["data"]["method_temp"][0] = {4, "电解池温度(℃)", item.method_temp4};
            resp->json["data"]["method_other"][0] = {0, "采样时间", item.method_other0};
            break;

        case 5: // 待机
            resp->json["data"]["method_temp"][0] = {0, "炉温(℃)", item.method_temp0};
            resp->json["data"]["method_temp"][1] = {1, "氮加热(℃)", item.method_temp1};
            resp->json["data"]["method_temp"][2] = {2, "氮制冷(℃)", item.method_temp2};
            resp->json["data"]["method_temp"][3] = {3, "催化剂温度(℃)", item.method_temp3};
            resp->json["data"]["method_temp"][4] = {4, "电解池温度(℃)", item.method_temp4};
            resp->json["data"]["method_pass"][0] = {0, "系统压力", item.method_pass0};
            resp->json["data"]["method_pass"][1] = {1, "氯压力", item.method_pass1};
            resp->json["data"]["method_flow"][0] = {0, "载气", item.method_flow0};
            resp->json["data"]["method_flow"][1] = {1, "氧气", item.method_flow1};
            resp->json["data"]["method_flow"][2] = {2, "臭氧", item.method_flow2};
            resp->json["data"]["method_flow"][3] = {3, "裂解氧(%)", item.method_flow3};
            resp->json["data"]["method_other"][0] = {0, "采样时间", item.method_other0};
            resp->json["data"]["method_other"][1] = {1, "裂解时间", item.method_other1};
            resp->json["data"]["method_other"][2] = {2, "氮高压", item.method_other2};
            resp->json["data"]["method_other"][3] = {3, "硫高压", item.method_other3};
            resp->json["data"]["method_other"][4] = {4, "氙灯高压", item.method_other4};
            break;

        case 6: // 启动
            resp->json["data"]["method_temp"][0] = {0, "炉温(℃)", item.method_temp0};
            resp->json["data"]["method_temp"][1] = {1, "氮加热(℃)", item.method_temp1};
            resp->json["data"]["method_temp"][2] = {2, "氮制冷(℃)", item.method_temp2};
            resp->json["data"]["method_temp"][3] = {3, "催化剂温度(℃)", item.method_temp3};
            resp->json["data"]["method_temp"][4] = {4, "电解池温度(℃)", item.method_temp4};
            resp->json["data"]["method_pass"][0] = {0, "系统压力", item.method_pass0};
            resp->json["data"]["method_pass"][1] = {1, "氯压力", item.method_pass1};
            resp->json["data"]["method_flow"][0] = {0, "载气", item.method_flow0};
            resp->json["data"]["method_flow"][1] = {1, "氧气", item.method_flow1};
            resp->json["data"]["method_flow"][2] = {2, "臭氧", item.method_flow2};
            resp->json["data"]["method_flow"][3] = {3, "裂解氧(%)", item.method_flow3};
            resp->json["data"]["method_other"][0] = {0, "采样时间", item.method_other0};
            resp->json["data"]["method_other"][1] = {1, "裂解时间", item.method_other1};
            resp->json["data"]["method_other"][2] = {2, "氮高压", item.method_other2};
            resp->json["data"]["method_other"][3] = {3, "硫高压", item.method_other3};
            resp->json["data"]["method_other"][4] = {4, "氙灯高压", item.method_other4};
            break;

        default:
            break;
        }
        // 根据进样器类型渲染内容
        if (injector_type == 0) // AJ
        {
            switch (sample_type)
            {
            case 0: // 液体
            case 1: // 气体
            case 2: // 固体
                resp->json["data"]["method_injector"][0] = {5, "进样速度", item.method_injector5};
                resp->json["data"]["method_injector"][1] = {6, "注射器容积", item.method_injector6};
                resp->json["data"]["method_injector"][2] = {9, "返回速度", item.method_injector9};
                break;
            }
        }
        else if (injector_type == 1) // 液体
        {
            switch (sample_type)
            {
            case 0: // 液体
            case 1: // 气体
            case 2: // 固体
                resp->json["data"]["method_injector"][0] = {0, "清洗次数1", item.method_injector0};
                resp->json["data"]["method_injector"][1] = {1, "清洗次数2", item.method_injector1};
                resp->json["data"]["method_injector"][2] = {2, "置换次数", item.method_injector2};
                resp->json["data"]["method_injector"][3] = {3, "提取速度(ul/s)", item.method_injector3};
                resp->json["data"]["method_injector"][4] = {4, "排出速度(ul/s)", item.method_injector4};
                resp->json["data"]["method_injector"][5] = {5, "进样速度(ul/s)", item.method_injector5};
                resp->json["data"]["method_injector"][6] = {6, "注射器容积", item.method_injector6};
                resp->json["data"]["method_injector"][7] = {7, "清洗体积", item.method_injector7};
                resp->json["data"]["method_injector"][8] = {8, "容差体积", item.method_injector8};
                resp->json["data"]["method_injector"][9] = {16, "扎入比例", item.method_injector16};
                break;
            }
        }
        else if (injector_type == 2) // 气体
        {
            switch (sample_type)
            {
            case 0: // 液体
            case 1: // 气体
            case 2: // 固体
                resp->json["data"]["method_injector"][0] = {0, "清洗次数1", item.method_injector0};
                resp->json["data"]["method_injector"][1] = {3, "提取速度(mL/s)", item.method_injector3};
                resp->json["data"]["method_injector"][2] = {5, "进样速度(mL/s)", item.method_injector5};
                break;
            }
        }
        else if (injector_type == 3) // 固体
        {
            switch (sample_type)
            {
            case 0: // 液体
                resp->json["data"]["method_injector"][0] = {5, "进样速度(ul/s)", item.method_injector5};
                resp->json["data"]["method_injector"][1] = {6, "注射器容积(ul)", item.method_injector6};
                resp->json["data"]["method_injector"][2] = {10, "总行程(mm)", item.method_injector10};
                resp->json["data"]["method_injector"][3] = {11, "快进速度(mm/s)", item.method_injector11};
                break;
            case 1: // 气体
                resp->json["data"]["method_injector"][0] = {5, "进样速度(mL/s)", item.method_injector5};
                resp->json["data"]["method_injector"][1] = {6, "注射器容积(mL)", item.method_injector6};
                resp->json["data"]["method_injector"][2] = {10, "总行程(mm)", item.method_injector10};
                resp->json["data"]["method_injector"][3] = {11, "快进速度(mm/s)", item.method_injector11};
                break;
            case 2: // 固体
                resp->json["data"]["method_injector"][0] = {5, "进样速度(mm/s)", item.method_injector5};
                resp->json["data"]["method_injector"][1] = {11, "快进速度(mm/s)", item.method_injector11};
                resp->json["data"]["method_injector"][2] = {12, "减速位(mm)", item.method_injector12};
                resp->json["data"]["method_injector"][3] = {13, "燃烧位(mm)", item.method_injector13};
                resp->json["data"]["method_injector"][4] = {14, "冷却温度", item.method_injector14};
                resp->json["data"]["method_injector"][5] = {15, "加热温度", item.method_injector15};
                break;
            }
        }
        else if (injector_type == 4) // 无
        {
            switch (sample_type)
            {
            case 0: // 液体
            case 1: // 气体
            case 2: // 固体
                break;
            }
        }
    };

    Handler::response_json(req, resp, func);
    return 200;
}
int MethodListHandler::copy(HttpRequest *req, HttpResponse *resp)
{
    auto func = [req, resp]
    {
        time_t now = std::time(NULL);
        int id = std::stoi(req->GetParam("id"));
        MethodListTable item;
        if (id == -1)
        {
            item.method_name = "未命名" + std::to_string(now); // 如果没有id，则使用默认名称
        }
        else
        {
            Model::get(item, id);
            item.method_name += std::to_string(now); // 添加ID到名称后面
        }
        resp->json["data"] = Model::insert(item); // 插入到方法列表中
    };

    Handler::response_json(req, resp, func);
    return 200;
}

int MethodListHandler::config(HttpRequest *req, HttpResponse *resp)
{
    auto func = [req, resp]
    {
        resp->json["data"]["method_type"] = {"单硫", "单氮", "单氯", "硫氮", "CELL", "待机", "启动"};
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
