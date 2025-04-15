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
#ifdef DEBUG_MODE
static auto storage = make_storage("../etc/database.db",
#else
static auto storage = make_storage("./etc/database.db",
#endif
                                   //  标定
                                   make_table("calibration",
                                              make_column("id",
                                                          &CalibrationTable::id, primary_key().autoincrement()),
                                              make_column("calibration_line",
                                                          &CalibrationTable::calibration_line, null()),
                                              make_column("calibration_signalnumber",
                                                          &CalibrationTable::calibration_signalnumber, null()),
                                              make_column("calibration_queue",
                                                          &CalibrationTable::calibration_queue, null()),
                                              make_column("calibration_order",
                                                          &CalibrationTable::calibration_order, null()),
                                              make_column("calibration_intercept",
                                                          &CalibrationTable::calibration_intercept, null()),
                                              make_column("calibration_A",
                                                          &CalibrationTable::calibration_A, null()),
                                              make_column("calibration_B",
                                                          &CalibrationTable::calibration_B, null()),
                                              make_column("calibration_C",
                                                          &CalibrationTable::calibration_C, null()),
                                              make_column("calibration_regression",
                                                          &CalibrationTable::calibration_regression, null()),
                                              make_column("calibration_min",
                                                          &CalibrationTable::calibration_min, null()),
                                              make_column("calibration_max",
                                                          &CalibrationTable::calibration_max, null()),
                                              make_column("calibration_calculated",
                                                          &CalibrationTable::calibration_calculated, null())),
                                   // 配置
                                   make_table("configuration",
                                              make_column("id",
                                                          &ConfigurationTable::id, primary_key().autoincrement()),
                                              make_column("config_parameternumber",
                                                          &ConfigurationTable::config_parameternumber, null()),
                                              make_column("config_name",
                                                          &ConfigurationTable::config_name, null()),
                                              make_column("config_parametername",
                                                          &ConfigurationTable::config_parametername, null()),
                                              make_column("config_floatvalue",
                                                          &ConfigurationTable::config_floatvalue, null()),
                                              make_column("config_integervalue",
                                                          &ConfigurationTable::config_integervalue, null()),
                                              make_column("config_stringvalue",
                                                          &ConfigurationTable::config_stringvalue, null()),
                                              make_column("config_booleanvalue",
                                                          &ConfigurationTable::config_booleanvalue, null())),
                                   // 方法列表
                                   make_table("method_list",
                                              make_column("id",
                                                          &MethodListTable::id, primary_key().autoincrement()),
                                              make_column("name",
                                                          &MethodListTable::name, null()),
                                              make_column("type",
                                                          &MethodListTable::type, null()),
                                              make_column("injector_type",
                                                          &MethodListTable::injector_type, null()),
                                              make_column("sample_type",
                                                          &MethodListTable::sample_type, null()),
                                              make_column("method_temp0",
                                                          &MethodListTable::method_temp0, null()),
                                              make_column("method_temp1",
                                                          &MethodListTable::method_temp1, null()),
                                              make_column("method_temp2",
                                                          &MethodListTable::method_temp2, null()),
                                              make_column("method_temp3",
                                                          &MethodListTable::method_temp3, null()),
                                              make_column("method_temp4",
                                                          &MethodListTable::method_temp4, null()),
                                              make_column("method_temp5",
                                                          &MethodListTable::method_temp5, null()),
                                              make_column("method_flow0",
                                                          &MethodListTable::method_flow0, null()),
                                              make_column("method_flow1",
                                                          &MethodListTable::method_flow1, null()),
                                              make_column("method_flow2",
                                                          &MethodListTable::method_flow2, null()),
                                              make_column("method_flow3",
                                                          &MethodListTable::method_flow3, null()),
                                              make_column("method_flow4",
                                                          &MethodListTable::method_flow4, null()),
                                              make_column("method_flow5",
                                                          &MethodListTable::method_flow5, null()),
                                              make_column("method_pass0",
                                                          &MethodListTable::method_pass0, null()),
                                              make_column("method_pass1",
                                                          &MethodListTable::method_pass1, null()),
                                              make_column("method_pass2",
                                                          &MethodListTable::method_pass2, null()),
                                              make_column("method_pass3",
                                                          &MethodListTable::method_pass3, null()),
                                              make_column("method_pass4",
                                                          &MethodListTable::method_pass4, null()),
                                              make_column("method_pass5",
                                                          &MethodListTable::method_pass5, null()),
                                              make_column("method_other0",
                                                          &MethodListTable::method_other0, null()),
                                              make_column("method_other1",
                                                          &MethodListTable::method_other1, null()),
                                              make_column("method_other2",
                                                          &MethodListTable::method_other2, null()),
                                              make_column("method_other3",
                                                          &MethodListTable::method_other1, null()),
                                              make_column("method_other4",
                                                          &MethodListTable::method_other4, null()),
                                              make_column("method_other5",
                                                          &MethodListTable::method_other5, null()),
                                              make_column("method_injector0",
                                                          &MethodListTable::method_injector0, null()),
                                              make_column("method_injector1",
                                                          &MethodListTable::method_injector1, null()),
                                              make_column("method_injector2",
                                                          &MethodListTable::method_injector2, null()),
                                              make_column("method_injector3",
                                                          &MethodListTable::method_injector3, null()),
                                              make_column("method_injector4",
                                                          &MethodListTable::method_injector4, null()),
                                              make_column("method_injector5",
                                                          &MethodListTable::method_injector5, null()),
                                              make_column("method_injector6",
                                                          &MethodListTable::method_injector6, null()),
                                              make_column("method_injector7",
                                                          &MethodListTable::method_injector7, null()),
                                              make_column("method_injector8",
                                                          &MethodListTable::method_injector8, null()),
                                              make_column("method_injector9",
                                                          &MethodListTable::method_injector9, null()),
                                              make_column("method_injector10",
                                                          &MethodListTable::method_injector10, null()),
                                              make_column("method_injector11",
                                                          &MethodListTable::method_injector11, null()),
                                              make_column("method_injector12",
                                                          &MethodListTable::method_injector12, null()),
                                              make_column("method_injector13",
                                                          &MethodListTable::method_injector13, null()),
                                              make_column("method_injector14",
                                                          &MethodListTable::method_injector14, null()),
                                              make_column("method_injector15",
                                                          &MethodListTable::method_injector15, null()),
                                              make_column("method_injector16",
                                                          &MethodListTable::method_injector16, null())),
                                   // 队列列表
                                   make_table("queue_list",
                                              make_column("id",
                                                          &QueueListTable::id, primary_key().autoincrement()),
                                              make_column("queue_number",
                                                          &QueueListTable::queue_number, null()),
                                              make_column("queue_signalnumber",
                                                          &QueueListTable::queue_signalnumber, null()),
                                              make_column("queue_name",
                                                          &QueueListTable::queue_name, null()),
                                              make_column("queue_comment",
                                                          &QueueListTable::queue_comment, null()),
                                              make_column("queue_element",
                                                          &QueueListTable::queue_element, null()),
                                              make_column("queue_blanco",
                                                          &QueueListTable::queue_blanco, null()),
                                              make_column("queue_yield",
                                                          &QueueListTable::queue_yield, null()),
                                              make_column("queue_calibrationqueue",
                                                          &QueueListTable::queue_calibrationqueue, null()),
                                              make_column("queue_calibration_signalnumber",
                                                          &QueueListTable::queue_calibration_signalnumber, null()),
                                              make_column("queue_calibration_order",
                                                          &QueueListTable::queue_calibration_order, null()),
                                              make_column("queue_intercept",
                                                          &QueueListTable::queue_intercept, null()),
                                              make_column("queue_calibrationa",
                                                          &QueueListTable::queue_calibrationa, null()),
                                              make_column("queue_calibrationb",
                                                          &QueueListTable::queue_calibrationb, null()),
                                              make_column("queue_calibrationc",
                                                          &QueueListTable::queue_calibrationc, null()),
                                              make_column("queue_regression",
                                                          &QueueListTable::queue_regression, null()),
                                              make_column("queue_calibration_min",
                                                          &QueueListTable::queue_calibration_min, null()),
                                              make_column("queue_calibration_max",
                                                          &QueueListTable::queue_calibration_max, null()),
                                              make_column("queue_timewindow",
                                                          &QueueListTable::queue_timewindow, null()),
                                              make_column("queue_treshold0",
                                                          &QueueListTable::queue_treshold0, null()),
                                              make_column("queue_treshold1",
                                                          &QueueListTable::queue_treshold1, null()),
                                              make_column("queue_treshold2",
                                                          &QueueListTable::queue_treshold2, null()),
                                              make_column("queue_baseline",
                                                          &QueueListTable::queue_baseline, null()),
                                              make_column("queue_posintegration",
                                                          &QueueListTable::queue_posintegration, null()),
                                              make_column("queue_calculated",
                                                          &QueueListTable::queue_calculated, null()),
                                              make_column("queue_blancocal",
                                                          &QueueListTable::queue_blancocal, null()),
                                              make_column("queue_TrashTime1",
                                                          &QueueListTable::queue_TrashTime1, null()),
                                              make_column("queue_AverageTime1",
                                                          &QueueListTable::queue_AverageTime1, null()),
                                              make_column("queue_TrashTime2",
                                                          &QueueListTable::queue_TrashTime2, null()),
                                              make_column("queue_AverageTime2",
                                                          &QueueListTable::queue_AverageTime2, null()),
                                              make_column("queue_calibrationline",
                                                          &QueueListTable::queue_calibrationline, null())),
                                   // 样本数据
                                   make_table("sample_data",
                                              make_column("id",
                                                          &SampleDataTable::id, primary_key().autoincrement()),
                                              make_column("sample_data_id",
                                                          &SampleDataTable::sample_data_id, null()),
                                              make_column("queue_number",
                                                          &SampleDataTable::queue_number, null()),
                                              make_column("sample_number",
                                                          &SampleDataTable::sample_number, null()),
                                              make_column("sample_signalnumber",
                                                          &SampleDataTable::sample_signalnumber, null()),
                                              make_column("sample_time",
                                                          &SampleDataTable::sample_time, null()),
                                              make_column("sample_data",
                                                          &SampleDataTable::sample_data, null())),
                                   // 样本列表
                                   make_table("sample_list",
                                              make_column("id",
                                                          &SampleListTable::id, primary_key().autoincrement()),
                                              make_column("queue_number",
                                                          &SampleListTable::queue_number, null(), null()),
                                              make_column("sample_number",
                                                          &SampleListTable::sample_number, null()),
                                              make_column("sample_signalnumber",
                                                          &SampleListTable::sample_signalnumber, null()),
                                              make_column("sample_name",
                                                          &SampleListTable::sample_name, null()),
                                              make_column("sample_area",
                                                          &SampleListTable::sample_area, null()),
                                              make_column("sample_amount",
                                                          &SampleListTable::sample_amount, null()),
                                              make_column("sample_amountunit",
                                                          &SampleListTable::sample_amountunit, null()),
                                              make_column("sample_startamount",
                                                          &SampleListTable::sample_startamount, null()),
                                              make_column("sample_startamount_unit",
                                                          &SampleListTable::sample_startamount_unit, null()),
                                              make_column("sample_place",
                                                          &SampleListTable::sample_place, null()),
                                              make_column("sample_dilution",
                                                          &SampleListTable::sample_dilution, null()),
                                              make_column("sample_density",
                                                          &SampleListTable::sample_density, null()),
                                              make_column("sample_molweight",
                                                          &SampleListTable::sample_molweight, null()),
                                              make_column("sample_tolerance",
                                                          &SampleListTable::sample_tolerance, null()),
                                              make_column("sample_type",
                                                          &SampleListTable::sample_type, null()),
                                              make_column("sample_method",
                                                          &SampleListTable::sample_method, null()),
                                              make_column("sample_result",
                                                          &SampleListTable::sample_result, null()),
                                              make_column("sample_date",
                                                          &SampleListTable::sample_date, null()),
                                              make_column("sample_comment",
                                                          &SampleListTable::sample_comment, null()),
                                              make_column("sample_log",
                                                          &SampleListTable::sample_log, null()),
                                              make_column("sample_analyst_name",
                                                          &SampleListTable::sample_analyst_name, null()),
                                              make_column("sample_totalcomponent",
                                                          &SampleListTable::sample_totalcomponent, null()),
                                              make_column("sample_cal_concentration",
                                                          &SampleListTable::sample_cal_concentration, null()),
                                              make_column("sample_concentration",
                                                          &SampleListTable::sample_concentration, null()),
                                              make_column("sample_conc_unit",
                                                          &SampleListTable::sample_conc_unit, null()),
                                              make_column("sample_beginpeak",
                                                          &SampleListTable::sample_beginpeak, null()),
                                              make_column("sample_beginpeak_value",
                                                          &SampleListTable::sample_beginpeak_value, null()),
                                              make_column("sample_endpeak",
                                                          &SampleListTable::sample_endpeak, null()),
                                              make_column("sample_endpeak_value",
                                                          &SampleListTable::sample_endpeak_value, null()),
                                              make_column("sample_id",
                                                          &SampleListTable::sample_id, null()),
                                              make_column("sample_mean",
                                                          &SampleListTable::sample_mean, null()),
                                              make_column("sample_vc",
                                                          &SampleListTable::sample_vc, null()),
                                              make_column("sample_sd",
                                                          &SampleListTable::sample_sd, null()),
                                              make_column("sample_flag",
                                                          &SampleListTable::sample_flag, null()),
                                              make_column("sample_temperature",
                                                          &SampleListTable::sample_temperature, null()),
                                              make_column("sample_pressure",
                                                          &SampleListTable::sample_pressure, null()),
                                              make_column("sample_calibration_line",
                                                          &SampleListTable::sample_calibration_line, null()),
                                              make_column("sample_loops",
                                                          &SampleListTable::sample_loops, null())));

class Model
{
public:
    // 同步数据库
    static void sync_schema()
    {
        storage.sync_schema();
    }

    // 通用获取列表函数
    template <typename T>
    static size_t get_all(std::vector<T> &list)
    {
        list = storage.template get_all<T>();
        return list.size();
    }

    // 通用插入函数
    template <typename T>
    static int insert(const T &record)
    {
        return storage.insert(record);
    }

    // 通用更新函数
    template <typename T>
    static void update(const T &record)
    {
        storage.update(record);
    }

    // 通用删除函数
    template <typename T>
    static void remove(const T &record, size_t id)
    {
        storage.template remove<T>(id); // 主键是 id
    }

    // 通用查找函数
    template <typename T>
    static bool get(T &record, size_t id)
    {
        try
        {
            record = storage.template get<T>(id);
            return true;
        }
        catch (std::system_error e)
        {
            char error[64];
            sprintf(error, "%s id:%zu %s", typeid(T).name(), id, e.what());
            throw std::invalid_argument(error); // 抛出一个标准异常
            return false;
        }
        catch (...)
        {
            char error[64];
            sprintf(error, "%s id:%zu unknown exeption", typeid(T).name(), id);
            throw std::invalid_argument(error); // 抛出一个标准异常
            return false;
        }
    }
};

#endif // HTTPD_MODEL_H
