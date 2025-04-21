//
// Created by zjw93 on 2025/3/26.
//

#include "SampleDataHandler.h"

#include "SampleData.h"
#include "handler.h"
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

int SampleDataHandler::get_all(HttpRequest *req, HttpResponse *resp) {
    auto func = [req, resp] {
        std::vector<SampleDataTable> list;
        size_t size = Model::get_all(list);
        if(size == 0)
        {
            resp->json["data"] = {};
            return;
        }
        int seq = 0;
        for (auto &item:list) {
            item.to_json(resp->json["data"][seq]);
            seq++;
        }
    };
    Handler::response_json(req, resp, func);
    return 200;
}

int SampleDataHandler::insert(HttpRequest *req, HttpResponse *resp) {
    auto func = [req, resp] {
        SampleDataTable item;
        item.from_json(req->GetJson());
        resp->json["data"] = Model::insert(item);
    };
    Handler::response_json(req, resp, func);
    return 200;
}

int SampleDataHandler::update(HttpRequest *req, HttpResponse *resp) {
    auto func = [req, resp] {
        SampleDataTable item;
        item.from_json(req->GetJson());

        Model::update(item);
        resp->json["data"] = item.id;
    };

    Handler::response_json(req, resp, func);
    return 200;
}

int SampleDataHandler::remove(HttpRequest *req, HttpResponse *resp) {
    auto func = [req, resp] {
        int id = std::stoi(req->GetParam("id"));
        SampleDataTable item;
        Model::remove(item, id);
        resp->json["data"] = id;
    };

    Handler::response_json(req, resp, func);
    return 200;
}

int SampleDataHandler::get(HttpRequest *req, HttpResponse *resp) {
    auto func = [req, resp] {
        int id = std::stoi(req->GetParam("id"));
        SampleDataTable item;
        Model::get(item, id);
        item.to_json(resp->json["data"]);
    };

    Handler::response_json(req, resp, func);
    return 200;
}
