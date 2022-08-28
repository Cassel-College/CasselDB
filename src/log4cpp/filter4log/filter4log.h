#ifndef LOG4CPP_FILTER4CLOG_FILTER4CLOG_H
#define LOG4CPP_FILTER4CLOG_FILTER4CLOG_H

#include <vector>

#include <log4cpp/level/level.h>
#include <log4cpp/log_module/log_module.h>

namespace log4cpp {

namespace filter4log {

using log4cpp::level::Level;
using log4cpp::log_module::LogModule;

class Filter4Log
{
    private:

        std::vector<LogModule> logs;
        Level level;

    public:

        Filter4Log();

        Filter4Log(std::vector<LogModule> &logs, const Level &level);

        ~Filter4Log();

        std::vector<LogModule> filter();

}; // class Filter4Log;

}; // namespace filter4log

}; // namespace log4cpp

#endif