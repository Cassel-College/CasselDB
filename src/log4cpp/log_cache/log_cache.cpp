#include <iostream>

#include "log_cache.h"
#include "log4cpp/filter4log/filter4log.h"

using log4cpp::filter4log::Filter4Log;

/**
 * @brief Construct a new log4cpp::log cache::LogCache::LogCache object
 * 
 * @version 0.1
 * @author liupeng (liupeng.0@outlook.com)
 * @date 2023-06-26
 * @copyright Copyright (c) 2023
 */
log4cpp::log_cache::LogCache::LogCache()
{
    ;
}

/**
 * @brief append logs
 * 
 * @param log 
 * @version 0.1
 * @author liupeng (liupeng.0@outlook.com)
 * @date 2023-06-26
 * @copyright Copyright (c) 2023
 */
void log4cpp::log_cache::LogCache::append(const LogModule &log, const Config4Log &config4log)
{
    this->logs.push_back(log);
    if (this->logs.size() >= 100) {
        this->run();
        this->save(config4log);
        this->clear();
    }
}

/**
 * @brief genaration logs info in vector.
 * 
 * @version 0.1
 * @author liupeng (liupeng.0@outlook.com)
 * @date 2023-06-26
 * @copyright Copyright (c) 2023
 */
void log4cpp::log_cache::LogCache::run()
{
    logs_info.clear();
    for (LogModule log : this->logs) {
        logs_info.push_back(log.get_log_info_with_style());
    }
}

/**
 * @brief get logs info
 * 
 * @return std::shared_ptr<std::vector<std::string>> 
 * @version 0.1
 * @author liupeng (liupeng.0@outlook.com)
 * @date 2023-06-28
 * @copyright Copyright (c) 2023
 * @return std::shared_ptr<std::vector<std::string>> 
 */
std::vector<std::string> log4cpp::log_cache::LogCache::get_logs_info() {
    return this->logs_info;
}

/**
 * @brief filtter logs by level
 * 
 * @param level 
 * @version 0.1
 * @author liupeng (liupeng.0@outlook.com)
 * @date 2023-06-26
 * @copyright Copyright (c) 2023
 */
void log4cpp::log_cache::LogCache::filtter(const Level &level)
{
    Filter4Log *log_filter = new Filter4Log(this->logs, level);
    this->logs = log_filter->filter();
    delete log_filter;
}

/**
 * @brief show logs
 * 
 * @version 0.1
 * @author liupeng (liupeng.0@outlook.com)
 * @date 2023-06-26
 * @copyright Copyright (c) 2023
 */
void log4cpp::log_cache::LogCache::show()
{
    for (LogModule log : this->logs) {
        log.show_log();
    }
}

/**
 * @brief clear logs and logs info
 * 
 * @version 0.1
 * @author liupeng (liupeng.0@outlook.com)
 * @date 2023-06-26
 * @copyright Copyright (c) 2023
 */
void log4cpp::log_cache::LogCache::clear()
{
    this->logs.clear();
    this->logs_info.clear();
}

void log4cpp::log_cache::LogCache::save(const Config4Log &config4log) {
    std::shared_ptr<Log2File> log2file_ptr = std::make_shared<Log2File>(config4log);
    log2file_ptr->WriteLogs(this->logs_info);
}

/**
 * @brief set log path
 * 
 * @param log_path 
 * @version 0.1
 * @author liupeng (liupeng.0@outlook.com)
 * @date 2023-06-28
 * @copyright Copyright (c) 2023
 */
void log4cpp::log_cache::LogCache::SetLogPath(const std::string &log_path) {
    this->log_path = log_path;
}

/**
 * @brief Get the Log Path object
 * 
 * @return const std::string& 
 * @version 0.1
 * @author liupeng (liupeng.0@outlook.com)
 * @date 2023-06-28
 * @copyright Copyright (c) 2023
 * @return const std::string& 
 */
const std::string &log4cpp::log_cache::LogCache::GetLogPath() {
    return this->log_path;
}