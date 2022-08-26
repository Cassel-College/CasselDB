#include "style4log.h"

#include <log4cpp/log_module/log_module.h>

using log4cpp::log_module::LogModule;


log4cpp::style4log::Style4Log::Style4Log()
{
    ;
}

log4cpp::style4log::Style4Log::Style4Log(const LogModule &log)
{
    this->log = log;
}

log4cpp::style4log::Style4Log::~Style4Log()
{
    ;
}

void log4cpp::style4log::Style4Log::set_log(const LogModule &log)
{
    this->log = log;
}
        
void log4cpp::style4log::Style4Log::set_style(const std::vector<std::pair<std::string, std::string>> &style)
{
    this->style = style;
}

std::string log4cpp::style4log::Style4Log::get_log_information()
{
    return "log infomation as space style.";
}