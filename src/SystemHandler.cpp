//
// Created by zjw93 on 2025/3/23.
//

#include "SystemHandler.h"

#include "handler.h"
#include <thread>   // import std::thread
#include <chrono>   // import std::chrono

#include "hbase.h"
#include "htime.h"
#include "hfile.h"
#include "hstring.h"
#include "EventLoop.h" // import setTimeout, setInterval
#include <sqlite_orm/sqlite_orm.h>


struct User {
    int id;
    std::string firstName;
    std::string lastName;
    int birthDate;
    std::unique_ptr<std::string> imageUrl;
    int typeId;
};

struct UserType {
    int id;
    std::string name;
};


int SystemHandler::menu(HttpRequest *req, HttpResponse *resp) {
    resp->content_type = APPLICATION_JSON;

    uint8_t i = 0;
    uint8_t j = 0;

    i = 0;
    j = 0;
    resp->json["data"][i]["title"] = "主页";
    resp->json["data"][i]["icon"] = "layui-icon-home";
    resp->json["data"][i]["list"][j]["title"] = "控制台";
    resp->json["data"][i]["list"][j]["jump"] = "/";
    j++;
    resp->json["data"][i]["list"][j]["title"] = "主页一";
    resp->json["data"][i]["list"][j]["jump"] = "home/homepage1";
    j++;
    resp->json["data"][i]["list"][j]["title"] = "主页二";
    resp->json["data"][i]["list"][j]["jump"] = "home/homepage2";

    i++;
    j = 0;
    resp->json["data"][i]["name"] = "component";
    resp->json["data"][i]["title"] = "组件";
    resp->json["data"][i]["icon"] = "layui-icon-component";
    resp->json["data"][i]["list"][j]["name"] = "button";
    resp->json["data"][i]["list"][j]["title"] = "按钮";
    j++;
    resp->json["data"][i]["list"][j]["name"] = "nav";
    resp->json["data"][i]["list"][j]["title"] = "导航";
    j++;
    resp->json["data"][i]["list"][j]["name"] = "tabs";
    resp->json["data"][i]["list"][j]["title"] = "选项卡";
    j++;
    resp->json["data"][i]["list"][j]["name"] = "progress";
    resp->json["data"][i]["list"][j]["title"] = "进度条";
    j++;
    resp->json["data"][i]["list"][j]["name"] = "panel";
    resp->json["data"][i]["list"][j]["title"] = "面板";
    j++;
    resp->json["data"][i]["list"][j]["name"] = "badge";
    resp->json["data"][i]["list"][j]["title"] = "徽章";
    j++;
    resp->json["data"][i]["list"][j]["name"] = "timeline";
    resp->json["data"][i]["list"][j]["title"] = "时间线";
    j++;
    resp->json["data"][i]["list"][j]["name"] = "anim";
    resp->json["data"][i]["list"][j]["title"] = "动画";
    j++;
    resp->json["data"][i]["list"][j]["name"] = "auxiliar";
    resp->json["data"][i]["list"][j]["title"] = "辅助";

    Handler::response_status(resp, 0, "OK");
    return 200;
}

int SystemHandler::test(HttpRequest *req, HttpResponse *resp) {
    resp->content_type = APPLICATION_JSON;

    using namespace sqlite_orm;
    using namespace std;
    auto storage = make_storage("../etc/database.db",
                                make_table("users",
                                           make_column("id", &User::id, primary_key().autoincrement()),
                                           make_column("first_name", &User::firstName),
                                           make_column("last_name", &User::lastName),
                                           make_column("birth_date", &User::birthDate),
                                           make_column("image_url", &User::imageUrl),
                                           make_column("type_id", &User::typeId)),
                                make_table("user_types",
                                           make_column("id", &UserType::id, primary_key().autoincrement()),
                                           make_column("name", &UserType::name, default_value("name_placeholder"))));

    try {
//        auto user = storage.get<User>(insertedId);
//        cout << "user = " << user.firstName << " " << user.lastName << endl;

        User user{-1, "Jonh", "Doe", 664416000, std::make_unique<std::string>("url_to_heaven"), 3};

        auto insertedId = storage.insert(user);
        cout << "insertedId = " << insertedId << endl;      //  insertedId = 8
        user.id = insertedId;

        User secondUser{-1, "Alice", "Inwonder", 831168000, {}, 2};
        insertedId = storage.insert(secondUser);
        secondUser.id = insertedId;
    } catch (std::system_error e) {
        cout << e.what() << endl;
    } catch (...) {
        cout << "unknown exeption" << endl;
    }

    Handler::response_status(resp, 0, "OK");
    return 200;
}