#include <iostream>
#include "log_module.h"

log4cpp::log_module::LogModule::LogModule()
{
    this->level = Level();
}


log4cpp::log_module::LogModule::LogModule(const std::string &log_info, Level level)
{
    this->log_info = log_info;
    this->level = level;
}

log4cpp::log_module::LogModule::~LogModule()
{
    ;
}

void log4cpp::log_module::LogModule::set_log_info(const std::string &log_info)
{
    this->log_info = log_info;
}

std::string log4cpp::log_module::LogModule::get_log_info() const 
{
    return log_info;
}

void log4cpp::log_module::LogModule::show_log() const 
{
    std::cout << this->level.get_level() << ":" << this->log_info << std::endl;
}