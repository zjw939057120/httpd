//
// Created by zjw93 on 2025/3/26.
//

#include "SampleListHandler.h"

#include "SampleList.h"
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

int SampleListHandler::get_all(HttpRequest *req, HttpResponse *resp)
{
    auto func = [req, resp]
    {
        std::vector<SampleListTable> list;
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

int SampleListHandler::insert(HttpRequest *req, HttpResponse *resp)
{
    auto func = [req, resp]
    {
        SampleListTable item;
        item.from_json(req->GetJson());
        resp->json["data"] = Model::insert(item);
    };
    Handler::response_json(req, resp, func);
    return 200;
}

int SampleListHandler::update(HttpRequest *req, HttpResponse *resp)
{
    auto func = [req, resp]
    {
        SampleListTable item;
        item.from_json(req->GetJson());

        Model::update(item);
        resp->json["data"] = item.id;
    };

    Handler::response_json(req, resp, func);
    return 200;
}

int SampleListHandler::remove(HttpRequest *req, HttpResponse *resp)
{
    auto func = [req, resp]
    {
        int id = std::stoi(req->GetParam("id"));
        SampleListTable item;
        Model::remove(item, id);
        resp->json["data"] = id;
    };

    Handler::response_json(req, resp, func);
    return 200;
}

int SampleListHandler::get(HttpRequest *req, HttpResponse *resp)
{
    auto func = [req, resp]
    {
        int id = std::stoi(req->GetParam("id"));
        SampleListTable item;
        Model::get(item, id);
        item.to_json(resp->json["data"]);
    };

    Handler::response_json(req, resp, func);
    return 200;
}

int SampleListHandler::get_all_by_queue(HttpRequest *req, HttpResponse *resp)
{
    auto func = [req, resp]
    {
        // 从请求中获取 queue_number 参数
        int queue_number = std::stoi(req->GetParam("queue_number"));

        // 使用 sqlite_orm 查询符合条件的记录
        auto storage = Model::get_storage(); // 获取数据库存储对象
        auto list = storage.get_all<SampleListTable>(
            sqlite_orm::where(sqlite_orm::c(&SampleListTable::queue_number) == queue_number));

        // 如果没有找到记录，返回空数组
        if (list.empty())
        {
            resp->json["data"] = {};
            return;
        }

        // 将查询结果转换为 JSON 格式
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

int SampleListHandler::batchDelete(HttpRequest *req, HttpResponse *resp)
{
    auto func = [req, resp]
    {
        hv::Json json = req->GetJson();
        std::vector<int> ids = json["ids"].get<std::vector<int>>();

        for (auto id : ids)
        {
            SampleListTable item;
            Model::remove(item, id);
        }
        resp->json["data"] = ids;
    };

    Handler::response_json(req, resp, func);
    return 200;
}

int SampleListHandler::batchAnalyse(HttpRequest *req, HttpResponse *resp)
{
    auto func = [req, resp]
    {
        hv::Json json = req->GetJson();
        std::vector<int> ids = json["ids"].get<std::vector<int>>();

        resp->json["data"] = ids;
    };

    Handler::response_json(req, resp, func);
    return 200;
}

int SampleListHandler::analyseQueue(HttpRequest *req, HttpResponse *resp)
{
    auto func = [req, resp]
    {
        // 从请求中获取 queue_number 参数
        int queue_number = std::stoi(req->GetParam("queue_number"));
        resp->json["data"] = queue_number;
    };

    Handler::response_json(req, resp, func);
    return 200;
}

int SampleListHandler::analyseStop(HttpRequest *req, HttpResponse *resp)
{
    auto func = [req, resp] {

    };

    Handler::response_json(req, resp, func);
    return 200;
}
