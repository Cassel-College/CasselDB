#ifndef LOG4CPP_CACHE_CACHE_H
#define LOG4CPP_CACHE_CACHE_H

#include <vector>

#include "log4cpp/log_module/log_module.h"
#include "log4cpp/level/level.h"


namespace log4cpp {

using log4cpp::log_module::LogModule;
using log4cpp::level::Level;

namespace log_cache {

class LogCache {

    public:

        LogCache();

        void append(const LogModule &log);

        void run();

        void clear();

        void filtter(const Level &level);

        void show();

    private:

        int max_length = 1024;

        std::vector<LogModule> logs;

}; // class LogCache
}; // namespace log_cache
}; // namespace log4cpp

#endif