#ifndef LOG4CPP_LOG_MODULE_LOG_MODULE_H
#define LOG4CPP_LOG_MODULE_LOG_MODULE_H

#include <string>
#include <map>

#include <log4cpp/level/level.h>

namespace log4cpp {

namespace log_module {

using log4cpp::level::Level;

class LogModule
{
    private:

        std::string log_info;
        Level level;

    public:

        LogModule();

        LogModule(const std::string &log_info, Level level);

        ~LogModule();

        void set_log_info(const std::string &log_info);

        std::string get_log_info() const;
        
        void show_log() const;

        Level get_level();
}; // class LogModule;

}; // namespace log_module

}; // namespace log4cpp

#endif