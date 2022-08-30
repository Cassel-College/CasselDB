#include "config4log.h"

log4cpp::config4log::Config4Log::Config4Log() {

}

log4cpp::config4log::Config4Log::~Config4Log() {

}


void log4cpp::config4log::Config4Log::read_config(const std::string &condif_path)
{

}

std::string log4cpp::config4log::Config4Log::getLogWebServerIp() const 
{
     return logWebServerIp; 
}

void log4cpp::config4log::Config4Log::setLogWebServerIp(const std::string &logWebServerIp_) 
{
     logWebServerIp = logWebServerIp_; 
}

int log4cpp::config4log::Config4Log::getLogWebServerPort() const 
{
     return logWebServerPort; 
}

void log4cpp::config4log::Config4Log::setLogWebServerPort(int logWebServerPort_) 
{
     logWebServerPort = logWebServerPort_; 
}

std::string log4cpp::config4log::Config4Log::getLogPath() const 
{
     return logPath; 
}

void log4cpp::config4log::Config4Log::setLogPath(const std::string &logPath_) 
{
     logPath = logPath_; 
}

int log4cpp::config4log::Config4Log::getMaxCache() const 
{
     return maxCache; 
}

void log4cpp::config4log::Config4Log::setMaxCache(int maxCache_) 
{
     maxCache = maxCache_; 
}

int log4cpp::config4log::Config4Log::getMaxSaveTime() const 
{
     return maxSaveTime; 
}

void log4cpp::config4log::Config4Log::setMaxSaveTime(int maxSaveTime_) 
{
     maxSaveTime = maxSaveTime_; 
}

int log4cpp::config4log::Config4Log::getMaxLogFileSize() const 
{
     return maxLogFileSize; 
}

void log4cpp::config4log::Config4Log::setMaxLogFileSize(int maxLogFileSize_) 
{
     maxLogFileSize = maxLogFileSize_; 
}

std::string log4cpp::config4log::Config4Log::getLogStyle() const 
{
     return logStyle; 
}

void log4cpp::config4log::Config4Log::setLogStyle(const std::string &logStyle_) 
{
     logStyle = logStyle_; 
}

std::string log4cpp::config4log::Config4Log::getFilterLevel() const 
{
     return filterLevel; 
}

void log4cpp::config4log::Config4Log::setFilterLevel(const std::string &filterLevel_) 
{
     filterLevel = filterLevel_; 
}

std::string log4cpp::config4log::Config4Log::getFilterModule() const 
{
     return filterModule; 
}

void log4cpp::config4log::Config4Log::setFilterModule(const std::string &filterModule_) 
{
     filterModule = filterModule_; 
}

std::string log4cpp::config4log::Config4Log::getLogCopyFileStyle() const 
{
     return logCopyFileStyle; 
}

void log4cpp::config4log::Config4Log::setLogCopyFileStyle(const std::string &logCopyFileStyle_) 
{
     logCopyFileStyle = logCopyFileStyle_; 
}
