//
// Created by zjw93 on 2025/3/23.
//

#include "MethodListHandler.h"

#include "MethodList.h"
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

int MethodListHandler::get_all(HttpRequest *req, HttpResponse *resp) {
    resp->content_type = APPLICATION_JSON;

    try {
        std::vector<MethodListTable> list;
        size_t size = Model::get_all(list);

        int seq = 0;
        for (auto &item:list) {
            item.to_json(resp->json["data"][seq]);
            seq++;
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

int MethodListHandler::insert(HttpRequest *req, HttpResponse *resp) {
    resp->content_type = APPLICATION_JSON;

    try {
        MethodListTable item;
        item.from_json(req->GetJson());
        resp->json["data"] = Model::insert(item);
        Handler::response_status(resp, 0, "OK");
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

int MethodListHandler::update(HttpRequest *req, HttpResponse *resp) {
    try {
        MethodListTable item;
        item.from_json(req->GetJson());

        Model::update(item);
        resp->json["data"] = item.id;
        Handler::response_status(resp, 0, "OK");
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

int MethodListHandler::remove(HttpRequest *req, HttpResponse *resp) {
    resp->content_type = APPLICATION_JSON;

    int id = atoi(req->GetParam("id").c_str());
    MethodListTable item;
    Model::remove(item, id);

    resp->json["data"] = id;
    Handler::response_status(resp, 0, "OK");
    return 200;
}

int MethodListHandler::get(HttpRequest *req, HttpResponse *resp) {
    resp->content_type = APPLICATION_JSON;

    auto id = req->GetParam("id");
    try {
        MethodListTable item;
        size_t size = Model::get(item, atoi(id.c_str()));
        if (size) {
           item.to_json(resp->json["data"]);
        } else {
            resp->json["data"] = {};
        }

        Handler::response_status(resp, 0, "OK");
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
