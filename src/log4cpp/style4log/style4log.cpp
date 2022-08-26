#include "style4log.h"

#include <log4cpp/log_module/log_module.h>
using log4cpp::log_module::LogModule;


log4cpp::style4log::Style4Log::Style4Log()
{
    ;
}

log4cpp::style4log::Style4Log::Style4Log(log4cpp::log_module::LogModule &log)
{
    this->log = log;
}

log4cpp::style4log::Style4Log::~Style4Log()
{
    ;
}

void log4cpp::style4log::Style4Log::set_log(LogModule &log)
{
    this->log = log;
}
        
void log4cpp::style4log::Style4Log::set_style()
{
    return;
}

std::string log4cpp::style4log::Style4Log::get_log_information()
{
    return "log infomation as space style.";
}