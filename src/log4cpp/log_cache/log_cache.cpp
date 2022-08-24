#include "log_cache.h"
#include <iostream>

log4cpp::log_cache::LogCache::LogCache()
{
    ;
}


void log4cpp::log_cache::LogCache::append(const LogModule &log)
{
    this->logs.push_back(log);
    if (this->logs.size() >= 3) {
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

void log4cpp::log_cache::LogCache::clear()
{
    this->logs.clear();
}