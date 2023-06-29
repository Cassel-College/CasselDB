#ifndef LOG4CPP_LOG_LOG_H
#define LOG4CPP_LOG_LOG_H

#include <vector>
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

class Log {

    public:

        Log(Log &other) = delete;
    
        void operator=(const Log &) = delete;

        ~Log();

        static Log *GetLog();

        static std::shared_ptr<Log> GetLogPtr();

        static std::vector<std::string> GetDefaultConfig();

        void add(const LogModule &log);

        void send_log();

        void clear();

        bool SetLogPath(const std::string &log_path);

    private:

        LogCache cache;

        Config4Log config;

        Style4Log style;

        std::vector<std::string> moduleFliters;

        Level levelFlite;

    protected:

        Log();

        Log(std::vector<std::string> defaultConfig);
        
        Log(Config4Log config);

        static Log* logMS;

        static std::shared_ptr<Log> logMS_ptr;

}; // class log;
}; // namespace log;
}; // namespace log4cpp;

#endif