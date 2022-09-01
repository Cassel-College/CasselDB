#include "log.h"

#include <log4cpp/log_module/log_module.h>
#include <log4cpp/level/level.h>
#include <log4cpp/log_cache/log_cache.h>
#include <log4cpp/style4log/style4log.h>
#include <log4cpp/io4log/io4log.h>
#include <log4cpp/filter4log/filter4log.h>
#include <log4cpp/config4log/config4log.h>
#include <log4cpp/date_time/date_time.h>

using log4cpp::log_module::LogModule;
using log4cpp::level::Level;
using log4cpp::log_cache::LogCache;
using log4cpp::style4log::Style4Log;
using log4cpp::io4log::IO4Log;
using log4cpp::filter4log::Filter4Log;
using log4cpp::config4log::Config4Log;
using log4cpp::date_time::DateTime;

log4cpp::log::Log::Log()
{
    cache = LogCache();
}

log4cpp::log::Log::~Log()
{
    ;
}

void log4cpp::log::Log::add(const LogModule &log)
{
    cache.append(log);
}

void log4cpp::log::Log::clear()
{
    cache.clear();
}

void log4cpp::log::Log::send_log()
{
    cache.show();
}