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
        for (auto const &item:list) {
            std::string str = storage.dump(item);
            resp->json["data"][seq] = nlohmann::json::parse(Utils::preprocessToJson(str));
            seq++;
        }

    } catch (std::system_error e) {
        std::cout << e.what() << std::endl;
    } catch (...) {
        std::cout << "unknown exeption" << std::endl;
    }

    Handler::response_status(resp, 0, "OK");
    return 200;
}

int MethodListHandler::insert(HttpRequest *req, HttpResponse *resp) {
    resp->content_type = APPLICATION_JSON;
    resp->json = req->GetJson();
    resp->json["int"] = 123;
    resp->json["float"] = 3.14;
    resp->json["string"] = "hello";

    Handler::response_status(resp, 0, "OK");
    return 200;
}

int MethodListHandler::update(HttpRequest *req, HttpResponse *resp) {
    resp->content_type = APPLICATION_JSON;
    resp->json = req->GetJson();
    resp->json["int"] = 123;
    resp->json["float"] = 3.14;
    resp->json["string"] = "hello";

    Handler::response_status(resp, 0, "OK");
    return 200;
}

int MethodListHandler::remove(HttpRequest *req, HttpResponse *resp) {
    resp->content_type = APPLICATION_JSON;
    resp->json = req->GetJson();
    resp->json["int"] = 123;
    resp->json["float"] = 3.14;
    resp->json["string"] = "hello";

    Handler::response_status(resp, 0, "OK");
    return 200;
}

int MethodListHandler::get(HttpRequest *req, HttpResponse *resp) {
    resp->content_type = APPLICATION_JSON;
    resp->json = req->GetJson();
    resp->json["int"] = 123;
    resp->json["float"] = 3.14;
    resp->json["string"] = "hello";

    Handler::response_status(resp, 0, "OK");
    return 200;
}
