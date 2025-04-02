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
    resp->content_type = APPLICATION_JSON;

    try {
        std::vector<ConfigurationTable> list;
        size_t size = Model::get_all(list);

        int seq = 0;
        for (auto &item:list) {
            item.to_json(resp->json["data"][seq]);
            seq++;
        }

    } catch (std::system_error e) {
        std::cout << e.what() << std::endl;
        Handler::response_status(resp, 0, e.what());
    } catch (...) {
        std::cout << "unknown exeption" << std::endl;
        Handler::response_status(resp, 0, "unknown exeption");
    }

    return 200;
}

int ConfigurationHandler::insert(HttpRequest *req, HttpResponse *resp) {
    resp->content_type = APPLICATION_JSON;

    try {
        ConfigurationTable item;
        item.from_json(req->GetJson());
        resp->json["data"] = Model::insert(item);
        Handler::response_status(resp, 0, "OK");
    } catch (std::system_error e) {
        std::cout << e.what() << std::endl;
        Handler::response_status(resp, 0, e.what());
    } catch (...) {
        std::cout << "unknown exeption" << std::endl;
        Handler::response_status(resp, 0, "unknown exeption");
    }

    return 200;
}

int ConfigurationHandler::update(HttpRequest *req, HttpResponse *resp) {
    try {
        ConfigurationTable item;
        item.from_json(req->GetJson());

        Model::update(item);
        resp->json["data"] = item.id;
        Handler::response_status(resp, 0, "OK");
    } catch (std::system_error e) {
        std::cout << e.what() << std::endl;
        Handler::response_status(resp, 0, e.what());
    } catch (...) {
        std::cout << "unknown exeption" << std::endl;
        Handler::response_status(resp, 0, "unknown exeption");
    }

    return 200;
}

int ConfigurationHandler::remove(HttpRequest *req, HttpResponse *resp) {
    resp->content_type = APPLICATION_JSON;

    int id = atoi(req->GetParam("id").c_str());
    ConfigurationTable item;
    Model::remove(item, id);

    resp->json["data"] = id;
    Handler::response_status(resp, 0, "OK");
    return 200;
}

int ConfigurationHandler::get(HttpRequest *req, HttpResponse *resp) {
    resp->content_type = APPLICATION_JSON;

    auto id = req->GetParam("id");
    try {
        ConfigurationTable item;
        size_t size = Model::get(item, atoi(id.c_str()));
        if (size) {
           item.to_json(resp->json["data"]);
        } else {
            resp->json["data"] = {};
        }

        Handler::response_status(resp, 0, "OK");
    } catch (std::system_error e) {
        std::cout << e.what() << std::endl;
        Handler::response_status(resp, 0, e.what());
    } catch (...) {
        std::cout << "unknown exeption" << std::endl;
        Handler::response_status(resp, 0, "unknown exeption");
    }

    return 200;
}
