#ifndef LOG4CPP_LOG_MODULE_LOG_MODULE_H
#define LOG4CPP_LOG_MODULE_LOG_MODULE_H

#include <string>
#include <map>

#include <log4cpp/level/level.h>
#include <log4cpp/date_time/date_time.h>

namespace log4cpp {

namespace log_module {

using log4cpp::level::Level;
using log4cpp::date_time::DateTime;

class LogModule
{
    private:

        DateTime datetime;
        Level level;
        std::string fileName;
        int line = -1;
        std::string functionName;
        std::string moduleName;
        std::string log_info;

    public:

        LogModule();

        LogModule(const std::string &log_info, Level level);

        LogModule(const std::string &log_info, const Level level, const std::string &moduleName, const std::string &filename, int line);

        ~LogModule();

        void set_log_info(const std::string &log_info);

        std::string get_log_info() const;
        
        void show_log() const;

        Level get_level();
}; // class LogModule;

}; // namespace log_module

}; // namespace log4cpp

#endif