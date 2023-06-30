#ifndef MODULE_SELECT_SELECT_DATABASE_H
#define MODULE_SELECT_SELECT_DATABASE_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <memory>

#include "core/select/select_dir/select_folder.h"
#include "config/cassel_config/cassel_config.h"
#include "module/config/path/data_path/data_path.h"

#include "log4cpp/log_module/log_module.h"
#include "log4cpp/level/level.h"
#include "log4cpp/log_cache/log_cache.h"
#include "log4cpp/style4log/style4log.h"
#include "log4cpp/io4log/io4log.h"
#include "log4cpp/filter4log/filter4log.h"
#include "log4cpp/config4log/config4log.h"
#include "log4cpp/date_time/date_time.h"
#include "log4cpp/log/log.h"


namespace module {
namespace select {
namespace select_databases {

using core::select::SelectFolder;
using module::config::path::DataPath;

using log4cpp::log_module::LogModule;
using log4cpp::level::Level;
using log4cpp::log_cache::LogCache;
using log4cpp::style4log::Style4Log;
using log4cpp::io4log::IO4Log;
using log4cpp::filter4log::Filter4Log;
using log4cpp::config4log::Config4Log;
using log4cpp::date_time::DateTime;
using log4cpp::log::Log;


class SelectDataBase {

public:

    SelectDataBase();

    ~SelectDataBase();

    bool DoSelect();

    bool AddDatabase(const std::string& database);

    std::shared_ptr<std::vector<std::string>> GetDatabaseNames();

private:

    std::shared_ptr<std::vector<std::string>> databases_infos_ptr;

};

}; // namespace select_databases
}; // namespace select
}; // namespace module

#endif // MODULE_SELECT_SELECT_DATABASE_H