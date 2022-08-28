#include <iostream>

#include "filter4log.h"

#include <log4cpp/log_module/log_module.h>
using log4cpp::log_module::LogModule;

log4cpp::filter4log::Filter4Log::Filter4Log()
{
    ;
}

log4cpp::filter4log::Filter4Log::Filter4Log(std::vector<LogModule> &logs, const Level &level)
{
    this->logs = logs;
    this->level = level;
}

log4cpp::filter4log::Filter4Log::~Filter4Log()
{
    ;
}

std::vector<LogModule> log4cpp::filter4log::Filter4Log::filter()
{
    std::vector<LogModule> target_logs = {};
    for (auto item : logs) {
        if (item.get_level().get_index() <= this->level.get_index()) {
            std::cout << item.get_level().get_index() << " <= " << this->level.get_index() << std::endl;
            target_logs.push_back(item);
        }
    }
    return target_logs;
}

