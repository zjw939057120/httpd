//
// Created by zjw93 on 2025/3/23.
//

#include "ConfigurationHandler.h"

#include "Configuration.h"
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

int ConfigurationHandler::get_all(HttpRequest *req, HttpResponse *resp) {
    auto func = [req, resp] {
        std::vector<ConfigurationTable> list;
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

int ConfigurationHandler::insert(HttpRequest *req, HttpResponse *resp) {
    auto func = [req, resp] {
        ConfigurationTable item;
        item.from_json(req->GetJson());
        resp->json["data"] = Model::insert(item);
    };
    Handler::response_json(req, resp, func);
    return 200;
}

int ConfigurationHandler::update(HttpRequest *req, HttpResponse *resp) {
    auto func = [req, resp] {
        ConfigurationTable item;
        item.from_json(req->GetJson());

        Model::update(item);
        resp->json["data"] = item.id;
    };

    Handler::response_json(req, resp, func);
    return 200;
}

int ConfigurationHandler::remove(HttpRequest *req, HttpResponse *resp) {
    auto func = [req, resp] {
        int id = std::stoi(req->GetParam("id"));
        ConfigurationTable item;
        Model::remove(item, id);
        resp->json["data"] = id;
    };

    Handler::response_json(req, resp, func);
    return 200;
}

int ConfigurationHandler::get(HttpRequest *req, HttpResponse *resp) {
    auto func = [req, resp] {
        int id = std::stoi(req->GetParam("id"));
        ConfigurationTable item;
        Model::get(item, id);
    };

    Handler::response_json(req, resp, func);
    return 200;
}
