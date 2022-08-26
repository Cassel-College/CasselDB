#ifndef LOG4CPP_STYLE4LOG_STYLE4LOG_H
#define LOG4CPP_STYLE4LOG_STYLE4LOG_H

#include <string>
#include <vector>
// #include <pair>
#include <log4cpp/log_module/log_module.h>


namespace log4cpp {

namespace style4log {

using log4cpp::log_module::LogModule;

class Style4Log {

    public:

        Style4Log();

        Style4Log(const LogModule &log);

        ~Style4Log();

        void set_log(const LogModule &log);

        void set_style(const std::vector<std::pair<std::string, std::string>> &style);

        std::string get_log_information();
    
    private:

        LogModule log;

        std::vector<std::pair<std::string, std::string>> style;

}; // class Style4Log

}; // namespace style4log

}; // namespace log4cpp
#endif