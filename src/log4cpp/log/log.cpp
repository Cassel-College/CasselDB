#include "log.h"
#include <memory>

#include <log4cpp/log_module/log_module.h>
#include <log4cpp/level/level.h>
#include <log4cpp/log_cache/log_cache.h>
#include <log4cpp/style4log/style4log.h>
#include <log4cpp/io4log/io4log.h>
#include <log4cpp/filter4log/filter4log.h>
#include <log4cpp/config4log/config4log.h>
#include <log4cpp/date_time/date_time.h>

namespace log4cpp {
namespace log {

using log4cpp::log_module::LogModule;
using log4cpp::level::Level;
using log4cpp::log_cache::LogCache;
using log4cpp::style4log::Style4Log;
using log4cpp::io4log::IO4Log;
using log4cpp::filter4log::Filter4Log;
using log4cpp::config4log::Config4Log;
using log4cpp::date_time::DateTime;

// Log::logMS = nullptr;

Log::Log()
{
    cache = LogCache();
}

Log::Log(std::vector<std::string> defaultConfig)
{
    
}

Log::~Log()
{
    ;
}

void Log::add(const LogModule &log)
{
    cache.append(log, this->config);
}

void Log::clear()
{
    cache.clear();
}

void Log::send_log()
{
    cache.show();
}

Log *Log::GetLog()
{
    if (logMS == nullptr) {
        // logMS = make_shared<Log>();
        // get log config path
        std::string log_config_path = "";
        logMS = new Log();
    }
    return logMS;
}

/**
 * @brief 
 * 
 * @return std::shared_ptr<Log> 
 * @version 0.1
 * @author liupeng (liupeng.0@outlook.com)
 * @date 2023-03-06
 * @copyright Copyright (c) 2023
 * @return std::shared_ptr<Log> 
 */
std::shared_ptr<Log> Log::GetLogPtr() {
    if (logMS_ptr == nullptr) {
        std::shared_ptr<Log> temp_log(new Log());
        logMS_ptr.swap(temp_log);
    }
    return logMS_ptr;
}

/**
 * @brief Set the Log Path object
 * 
 * @param log_path 
 * @return true 
 * @return false 
 * @version 0.1
 * @author liupeng (liupeng.0@outlook.com)
 * @date 2023-06-28
 * @copyright Copyright (c) 2023
 * @return true 
 * @return false 
 */
bool Log::SetLogPath(const std::string &log_path) {
    bool set_log_path_status = true;
    if (logMS_ptr != nullptr) {
        std::cout << "Setting log path:" << log_path << std::endl;
        logMS_ptr->config.setLogPath(log_path);
    } else {
        set_log_path_status = false;
    }

    if (logMS != nullptr) {
        std::cout << "Setting log path:" << log_path << std::endl;
        logMS->config.setLogPath(log_path);
    } else {
        set_log_path_status = false;
    }
    return set_log_path_status;
}

/**
 * @brief Get Default log Config
 * 
 * @return std::vector<std::string> 
 * @version 0.1
 * @author liupeng (liupeng.0@outlook.com)
 * @date 2023-06-28
 * @copyright Copyright (c) 2023
 * @return std::vector<std::string> 
 */
std::vector<std::string> Log::GetDefaultConfig()
{
    std::vector<std::string> config_infos;
    config_infos.push_back("log_web_server_ip=\"127.0.0.1\"");
    config_infos.push_back("log_web_server_port=\"8769\"");
    config_infos.push_back("log_path=/tmp/casseldb/cassel.log");
    config_infos.push_back("max_cache=1024");
    config_infos.push_back("max_save_time=300");
    config_infos.push_back("max_log_file_size=10240");
    config_infos.push_back("log_style=lp");
    config_infos.push_back("filter_level=debug");
    config_infos.push_back("filter_module=\"core\"");
    config_infos.push_back("log_copy_file_style=\"casseldb_yyyy_mm_dd_hh_mm_ss.log\"");
    return config_infos;
}

}; //namespace log4cpp
}; // namespace log
