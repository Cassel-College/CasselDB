#ifndef LOG4CPP_CACHE_CACHE_H
#define LOG4CPP_CACHE_CACHE_H

#include <string>
#include <vector>
#include <memory>

#include "log4cpp/log_module/log_module.h"
#include "log4cpp/level/level.h"
#include "log4cpp/log2file/log2file.h"

namespace log4cpp {

using log4cpp::log_module::LogModule;
using log4cpp::level::Level;
using log4cpp::log2file::Log2File;

namespace log_cache {

class LogCache {

    public:

        LogCache();

        void append(const LogModule &log);

        void run();

        void clear();

        void filtter(const Level &level);

        void show();

        std::vector<std::string> get_logs_info();

        void save();

        void SetLogPath(const std::string &log_path);

        const std::string &GetLogPath();
    

    private:

        int max_length = 1024;
        std::vector<LogModule> logs;
        std::vector<std::string> logs_info;
        std::string log_path;

}; // class LogCache
}; // namespace log_cache
}; // namespace log4cpp

#endif