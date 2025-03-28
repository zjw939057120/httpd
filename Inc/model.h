//
// Created by zjw93 on 2025/3/29.
//

#ifndef HTTPD_MODEL_H
#define HTTPD_MODEL_H

#include <sqlite_orm/sqlite_orm.h>
#include <hv/json.hpp>

using namespace sqlite_orm;


class Model {
public:
    // 通用创建表函数
    template<typename Storage>
    static void create(Storage &storage) {
        storage.sync_schema();
    }

    // 通用获取列表函数
    template<typename Storage, typename T>
    static size_t list_record(Storage &storage, std::vector<T> &list) {
        list = storage.template get_all<T>();
        return list.size();
    }

    // 通用插入函数
    template<typename Storage, typename T>
    static void insert_record(Storage &storage, const T &record) {
        storage.insert(record);
    }

    // 通用更新函数
    template<typename Storage, typename T>
    static void update_record(Storage &storage, const T &record) {
        storage.update(record);
    }

    // 通用删除函数
    template<typename Storage, typename T>
    static void delete_record(Storage &storage, const T &record, size_t id) {
        storage.template remove<T>(id); // 主键是 id
    }

    // 通用查找函数
    template<typename Storage, typename T>
    static bool find_record(Storage &storage, T &record, size_t id) {
        try {
            record = storage.template get<T>(id);
            return true;
        } catch (std::system_error e) {
            printf("%s %zu %s\r\n", typeid(T).name(), id, e.what());
            return false;
        } catch (...) {
            printf("%s %zu unknown exeption\r\n", typeid(T).name(), id);
            return false;
        }
    }
};

#endif //HTTPD_MODEL_H
