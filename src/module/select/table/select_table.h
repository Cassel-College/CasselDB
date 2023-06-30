#ifndef MODULE_SELECT_SELECT_TABLE_H
#define MODULE_SELECT_SELECT_TABLE_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <memory>

#include <log4cpp/log_module/log_module.h>
#include <log4cpp/level/level.h>
#include <log4cpp/log_cache/log_cache.h>
#include <log4cpp/style4log/style4log.h>
#include <log4cpp/io4log/io4log.h>
#include <log4cpp/filter4log/filter4log.h>
#include <log4cpp/config4log/config4log.h>
#include <log4cpp/date_time/date_time.h>
#include <log4cpp/log/log.h>

#include <core/select/select_dir/select_folder.h>


namespace module {
namespace select {
namespace select_table {

using log4cpp::log_module::LogModule;
using log4cpp::level::Level;
using log4cpp::log_cache::LogCache;
using log4cpp::style4log::Style4Log;
using log4cpp::io4log::IO4Log;
using log4cpp::filter4log::Filter4Log;
using log4cpp::config4log::Config4Log;
using log4cpp::date_time::DateTime;
using log4cpp::log::Log;

using core::select::SelectFolder;

class SelectTable {

public:

    SelectTable();

    SelectTable(const std::string& path);

    SelectTable(const std::string& path, const std::string& database_info);

    ~SelectTable();

    void SetDatabaseName(const std::string &database_name);

    std::shared_ptr<std::vector<std::string>> GetTableInfos();

    bool DoSelectTable();

private:

    std::string path;

    std::string database_info;

    std::shared_ptr<std::vector<std::string>> tables_info_ptr;


}; // class SelectTable

}; // namespace select_table
}; // namespace select
}; // namespace module

#endif