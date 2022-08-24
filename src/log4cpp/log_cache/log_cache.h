#ifndef LOG4CPP_CACHE_CACHE_H
#define LOG4CPP_CACHE_CACHE_H

#include <vector>

#include "log4cpp/log_module/log_module.h"


namespace log4cpp {

using log4cpp::log_module::LogModule;

namespace log_cache {

class LogCache {

    public:

        LogCache();

        void append(const LogModule &log);

        void run();

        void clear();

    private:

        int max_length = 1024;

        std::vector<LogModule> logs;

}; // class LogCache
}; // namespace log_cache
}; // namespace log4cpp

#endif