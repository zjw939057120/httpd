//
// Created by zjw93 on 2025/3/23.
//

#include "QueueListHandler.h"

#include "QueueList.h"
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

int QueueListHandler::get_all(HttpRequest *req, HttpResponse *resp)
{
    auto func = [req, resp]
    {
        std::vector<QueueListTable> list;
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

int QueueListHandler::insert(HttpRequest *req, HttpResponse *resp)
{
    auto func = [req, resp]
    {
        QueueListTable item;
        hv::Json json = req->GetJson(); 
        item.queue_name = json["queue_name"].get<std::string>();//队列名称
        item.queue_comment = json["queue_comment"].get<std::string>(); //队列备注
        resp->json["data"] = Model::insert(item);
    };
    Handler::response_json(req, resp, func);
    return 200;
}

int QueueListHandler::update(HttpRequest *req, HttpResponse *resp)
{
    auto func = [req, resp]
    {
        QueueListTable item;
        item.from_json(req->GetJson());

        Model::update(item);
        resp->json["data"] = item.id;
    };

    Handler::response_json(req, resp, func);
    return 200;
}

int QueueListHandler::remove(HttpRequest *req, HttpResponse *resp)
{
    auto func = [req, resp]
    {
        int id = std::stoi(req->GetParam("id"));
        QueueListTable item;
        Model::remove(item, id);
        resp->json["data"] = id;
    };

    Handler::response_json(req, resp, func);
    return 200;
}

int QueueListHandler::get(HttpRequest *req, HttpResponse *resp)
{
    auto func = [req, resp]
    {
        int id = std::stoi(req->GetParam("id"));
        QueueListTable item;
        Model::get(item, id);
        item.to_json(resp->json["data"]);
    };

    Handler::response_json(req, resp, func);
    return 200;
}

int QueueListHandler::copy(HttpRequest *req, HttpResponse *resp)
{
    auto func = [req, resp]
    {
        time_t now = std::time(NULL);
        int id = std::stoi(req->GetParam("id"));
        QueueListTable item;
        if (id == -1)
        {
            item.queue_name = "未命名" + std::to_string(now); // 如果没有id，则使用默认名称
        }
        else
        {
            Model::get(item, id);
            item.queue_name += std::to_string(now); // 添加ID到名称后面
        }
        resp->json["data"] = Model::insert(item); // 插入到方法列表中
    };

    Handler::response_json(req, resp, func);
    return 200;
}
