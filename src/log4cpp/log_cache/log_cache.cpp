#include <iostream>

#include "log_cache.h"
#include "log4cpp/filter4log/filter4log.h"

using log4cpp::filter4log::Filter4Log;

log4cpp::log_cache::LogCache::LogCache()
{
    ;
}

void log4cpp::log_cache::LogCache::append(const LogModule &log)
{
    this->logs.push_back(log);
    if (this->logs.size() >= 20) {
        this->run();
        this->clear();
        std::cout << "After clear length was " << this->logs.size() << std::endl;
    }
}

void log4cpp::log_cache::LogCache::run()
{
    for (LogModule log : this->logs) {
        log.show_log();
    }
}


void log4cpp::log_cache::LogCache::filtter(const Level &level)
{
    Filter4Log *log_filter = new Filter4Log(this->logs, level);
    this->logs = log_filter->filter();
    delete log_filter;
}

void log4cpp::log_cache::LogCache::show()
{
    for (LogModule log : this->logs) {
        log.show_log();
    }
}

void log4cpp::log_cache::LogCache::clear()
{
    this->logs.clear();
}