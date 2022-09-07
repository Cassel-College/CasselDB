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

using log4cpp::log_module::LogModule;
using log4cpp::level::Level;
using log4cpp::log_cache::LogCache;
using log4cpp::style4log::Style4Log;
using log4cpp::io4log::IO4Log;
using log4cpp::filter4log::Filter4Log;
using log4cpp::config4log::Config4Log;
using log4cpp::date_time::DateTime;

// log4cpp::log::Log::logMS = nullptr;

log4cpp::log::Log::Log()
{
    cache = LogCache();
}

log4cpp::log::Log::Log(std::vector<std::string> defaultConfig)
{
    
}

log4cpp::log::Log::~Log()
{
    ;
}

void log4cpp::log::Log::add(const LogModule &log)
{
    cache.append(log);
}

void log4cpp::log::Log::clear()
{
    cache.clear();
}

void log4cpp::log::Log::send_log()
{
    cache.show();
}

log4cpp::log::Log *log4cpp::log::Log::GetLog()
{
    if (logMS == nullptr) {
        // logMS = make_shared<Log>();
        // get log config path
        std::string log_config_path = "";
        logMS = new Log();
    }
    return logMS;
}

std::vector<std::string> log4cpp::log::Log::GetDefaultConfig()
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