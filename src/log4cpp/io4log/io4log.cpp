#include "io4log.h"

log4cpp::io4log::IO4Log::IO4Log()
{

}

log4cpp::io4log::IO4Log::IO4Log(const std::string &log_path)
{
    this->log_path = log_path;
}

log4cpp::io4log::IO4Log::~IO4Log()
{

}

void log4cpp::io4log::IO4Log::wirte(const std::string &log_info)
{
    std::cout << "Write log information to " << log_path << std::endl;
}