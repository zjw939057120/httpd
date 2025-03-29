//
// Created by zjw93 on 2025/3/29.
//

#ifndef HTTPD_MODEL_H
#define HTTPD_MODEL_H

#include <sqlite_orm/sqlite_orm.h>
#include <hv/json.hpp>
#include <iostream>
#include "Calibration.h"
#include "Configuration.h"
#include "MethodList.h"
#include "QueueList.h"
#include "SampleData.h"
#include "SampleList.h"

using namespace sqlite_orm;

static auto storage = make_storage("../etc/database.db",
        //标定
                                   make_table("calibration",
                                              make_column("id", &CalibrationTable::id,
                                                          primary_key().autoincrement()),
                                              make_column("calibration_line",
                                                          &CalibrationTable::calibration_line),
                                              make_column("calibration_signalnumber",
                                                          &CalibrationTable::calibration_signalnumber),
                                              make_column("calibration_queue",
                                                          &CalibrationTable::calibration_queue),
                                              make_column("calibration_order",
                                                          &CalibrationTable::calibration_order),
                                              make_column("calibration_intercept",
                                                          &CalibrationTable::calibration_intercept),
                                              make_column("calibration_A",
                                                          &CalibrationTable::calibration_A),
                                              make_column("calibration_B",
                                                          &CalibrationTable::calibration_B),
                                              make_column("calibration_C",
                                                          &CalibrationTable::calibration_C),
                                              make_column("calibration_regression",
                                                          &CalibrationTable::calibration_regression),
                                              make_column("calibration_min",
                                                          &CalibrationTable::calibration_min),
                                              make_column("calibration_max",
                                                          &CalibrationTable::calibration_max),
                                              make_column("calibration_calculated",
                                                          &CalibrationTable::calibration_calculated)
                                   ),
        //配置
                                   make_table("configuration",
                                              make_column("id", &ConfigurationTable::id,
                                                          primary_key().autoincrement()),
                                              make_column("config_parameternumber",
                                                          &ConfigurationTable::config_parameternumber),
                                              make_column("config_parametername",
                                                          &ConfigurationTable::config_parametername),
                                              make_column("config_floatvalue",
                                                          &ConfigurationTable::config_floatvalue),
                                              make_column("config_integervalue",
                                                          &ConfigurationTable::config_integervalue),
                                              make_column("config_stringvalue",
                                                          &ConfigurationTable::config_stringvalue),
                                              make_column("config_booleanvalue",
                                                          &ConfigurationTable::config_booleanvalue)
                                   ),
        //方法列表
                                   make_table("method_list",
                                              make_column("id", &MethodListTable::id,
                                                          primary_key().autoincrement()),
                                              make_column("method_number",
                                                          &MethodListTable::method_number),
                                              make_column("method_step",
                                                          &MethodListTable::method_step),
                                              make_column("method_stage",
                                                          &MethodListTable::method_stage),
                                              make_column("method_stepname",
                                                          &MethodListTable::method_stepname),
                                              make_column("method_timestep",
                                                          &MethodListTable::method_timestep),
                                              make_column("method_actionname",
                                                          &MethodListTable::method_actionname),
                                              make_column("method_actionnumber",
                                                          &MethodListTable::method_actionnumber),
                                              make_column("method_parametername1",
                                                          &MethodListTable::method_parametername1),
                                              make_column("method_parametername2",
                                                          &MethodListTable::method_parametername2),
                                              make_column("method_parametername3",
                                                          &MethodListTable::method_parametername3),
                                              make_column("method_parametername4",
                                                          &MethodListTable::method_parametername4),
                                              make_column("method_parametername5",
                                                          &MethodListTable::method_parametername5),
                                              make_column("method_parametername6",
                                                          &MethodListTable::method_parametername6),
                                              make_column("method_parametername7",
                                                          &MethodListTable::method_parametername7),
                                              make_column("method_parametername8",
                                                          &MethodListTable::method_parametername8),
                                              make_column("method_parametername9",
                                                          &MethodListTable::method_parametername9),
                                              make_column("method_parametername10",
                                                          &MethodListTable::method_parametername10),
                                              make_column("method_parametertype",
                                                          &MethodListTable::method_parametertype),
                                              make_column("method_parameter1",
                                                          &MethodListTable::method_parameter1),
                                              make_column("method_parameter2",
                                                          &MethodListTable::method_parameter2),
                                              make_column("method_parameter3",
                                                          &MethodListTable::method_parameter1),
                                              make_column("method_parameter4",
                                                          &MethodListTable::method_parameter4),
                                              make_column("method_parameter5",
                                                          &MethodListTable::method_parameter5),
                                              make_column("method_parameter6",
                                                          &MethodListTable::method_parameter6),
                                              make_column("method_parameter7",
                                                          &MethodListTable::method_parameter7),
                                              make_column("method_parameter8",
                                                          &MethodListTable::method_parameter8),
                                              make_column("method_parameter9",
                                                          &MethodListTable::method_parameter9),
                                              make_column("method_parameter10",
                                                          &MethodListTable::method_parameter10),
                                              make_column("method_config",
                                                          &MethodListTable::method_config)
                                   ),
        //队列列表
                                   make_table("queue_list",
                                              make_column("id", &QueueListTable::id,
                                                          primary_key().autoincrement()),
                                              make_column("queue_number",
                                                          &QueueListTable::queue_number),
                                              make_column("queue_signalnumber",
                                                          &QueueListTable::queue_signalnumber),
                                              make_column("queue_name",
                                                          &QueueListTable::queue_name),
                                              make_column("queue_comment",
                                                          &QueueListTable::queue_comment),
                                              make_column("queue_element",
                                                          &QueueListTable::queue_element),
                                              make_column("queue_blanco",
                                                          &QueueListTable::queue_blanco),
                                              make_column("queue_yield",
                                                          &QueueListTable::queue_yield),
                                              make_column("queue_calibrationqueue",
                                                          &QueueListTable::queue_calibrationqueue),
                                              make_column("queue_calibration_signalnumber",
                                                          &QueueListTable::queue_calibration_signalnumber),
                                              make_column("queue_calibration_order",
                                                          &QueueListTable::queue_calibration_order),
                                              make_column("queue_intercept",
                                                          &QueueListTable::queue_intercept),
                                              make_column("queue_calibrationa",
                                                          &QueueListTable::queue_calibrationa),
                                              make_column("queue_calibrationb",
                                                          &QueueListTable::queue_calibrationb),
                                              make_column("queue_calibrationc",
                                                          &QueueListTable::queue_calibrationc),
                                              make_column("queue_regression",
                                                          &QueueListTable::queue_regression),
                                              make_column("queue_calibration_min",
                                                          &QueueListTable::queue_calibration_min),
                                              make_column("queue_calibration_max",
                                                          &QueueListTable::queue_calibration_max),
                                              make_column("queue_timewindow",
                                                          &QueueListTable::queue_timewindow),
                                              make_column("queue_treshold0",
                                                          &QueueListTable::queue_treshold0),
                                              make_column("queue_treshold1",
                                                          &QueueListTable::queue_treshold1),
                                              make_column("queue_treshold2",
                                                          &QueueListTable::queue_treshold2),
                                              make_column("queue_baseline",
                                                          &QueueListTable::queue_baseline),
                                              make_column("queue_posintegration",
                                                          &QueueListTable::queue_posintegration),
                                              make_column("queue_calculated",
                                                          &QueueListTable::queue_calculated),
                                              make_column("queue_blancocal",
                                                          &QueueListTable::queue_blancocal),
                                              make_column("queue_TrashTime1",
                                                          &QueueListTable::queue_TrashTime1),
                                              make_column("queue_AverageTime1",
                                                          &QueueListTable::queue_AverageTime1),
                                              make_column("queue_TrashTime2",
                                                          &QueueListTable::queue_TrashTime2),
                                              make_column("queue_AverageTime2",
                                                          &QueueListTable::queue_AverageTime2),
                                              make_column("queue_calibrationline",
                                                          &QueueListTable::queue_calibrationline)
                                   ),
        //样本数据
                                   make_table("sample_data",
                                              make_column("id", &SampleDataTable::id,
                                                          primary_key().autoincrement()),
                                              make_column("sample_data_id",
                                                          &SampleDataTable::sample_data_id),
                                              make_column("queue_number",
                                                          &SampleDataTable::queue_number),
                                              make_column("sample_number",
                                                          &SampleDataTable::sample_number),
                                              make_column("sample_signalnumber",
                                                          &SampleDataTable::sample_signalnumber),
                                              make_column("sample_time",
                                                          &SampleDataTable::sample_time),
                                              make_column("sample_data",
                                                          &SampleDataTable::sample_data)
                                   ),
        //样本列表
                                   make_table("sample_list",
                                              make_column("id", &SampleListTable::id,
                                                          primary_key().autoincrement()),
                                              make_column("queue_number",
                                                          &SampleListTable::queue_number),
                                              make_column("sample_number",
                                                          &SampleListTable::sample_number),
                                              make_column("sample_signalnumber",
                                                          &SampleListTable::sample_signalnumber),
                                              make_column("sample_name",
                                                          &SampleListTable::sample_name),
                                              make_column("sample_area",
                                                          &SampleListTable::sample_area),
                                              make_column("sample_amount",
                                                          &SampleListTable::sample_amount),
                                              make_column("sample_amountunit",
                                                          &SampleListTable::sample_amountunit),
                                              make_column("sample_startamount",
                                                          &SampleListTable::sample_startamount),
                                              make_column("sample_startamount_unit",
                                                          &SampleListTable::sample_startamount_unit),
                                              make_column("sample_place",
                                                          &SampleListTable::sample_place),
                                              make_column("sample_dilution",
                                                          &SampleListTable::sample_dilution),
                                              make_column("sample_density",
                                                          &SampleListTable::sample_density),
                                              make_column("sample_molweight",
                                                          &SampleListTable::sample_molweight),
                                              make_column("sample_tolerance",
                                                          &SampleListTable::sample_tolerance),
                                              make_column("sample_type",
                                                          &SampleListTable::sample_type),
                                              make_column("sample_method",
                                                          &SampleListTable::sample_method),
                                              make_column("sample_result",
                                                          &SampleListTable::sample_result),
                                              make_column("sample_date",
                                                          &SampleListTable::sample_date),
                                              make_column("sample_comment",
                                                          &SampleListTable::sample_comment),
                                              make_column("sample_log",
                                                          &SampleListTable::sample_log),
                                              make_column("sample_analyst_name",
                                                          &SampleListTable::sample_analyst_name),
                                              make_column("sample_totalcomponent",
                                                          &SampleListTable::sample_totalcomponent),
                                              make_column("sample_cal_concentration",
                                                          &SampleListTable::sample_cal_concentration),
                                              make_column("sample_concentration",
                                                          &SampleListTable::sample_concentration),
                                              make_column("sample_conc_unit",
                                                          &SampleListTable::sample_conc_unit),
                                              make_column("sample_beginpeak",
                                                          &SampleListTable::sample_beginpeak),
                                              make_column("sample_beginpeak_value",
                                                          &SampleListTable::sample_beginpeak_value),
                                              make_column("sample_endpeak",
                                                          &SampleListTable::sample_endpeak),
                                              make_column("sample_endpeak_value",
                                                          &SampleListTable::sample_endpeak_value),
                                              make_column("sample_id",
                                                          &SampleListTable::sample_id),
                                              make_column("sample_mean",
                                                          &SampleListTable::sample_mean),
                                              make_column("sample_vc",
                                                          &SampleListTable::sample_vc),
                                              make_column("sample_sd",
                                                          &SampleListTable::sample_sd),
                                              make_column("sample_flag",
                                                          &SampleListTable::sample_flag),
                                              make_column("sample_temperature",
                                                          &SampleListTable::sample_temperature),
                                              make_column("sample_pressure",
                                                          &SampleListTable::sample_pressure),
                                              make_column("sample_calibration_line",
                                                          &SampleListTable::sample_calibration_line),
                                              make_column("sample_loops",
                                                          &SampleListTable::sample_loops)
                                   )
);

class Model {
public:
    // 同步数据库
    static void sync_table() {
        storage.sync_schema();
    }

    // 通用获取列表函数
    template<typename T>
    static size_t list_record(std::vector<T> &list) {
        list = storage.template get_all<T>();
        return list.size();
    }

    // 通用插入函数
    template<typename T>
    static void insert_record(const T &record) {
        storage.insert(record);
    }

    // 通用更新函数
    template<typename T>
    static void update_record(const T &record) {
        storage.update(record);
    }

    // 通用删除函数
    template<typename T>
    static void delete_record(const T &record, size_t id) {
        storage.template remove<T>(id); // 主键是 id
    }

    // 通用查找函数
    template<typename T>
    static bool find_record(T &record, size_t id) {
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
