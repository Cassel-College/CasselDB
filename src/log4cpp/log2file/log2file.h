#ifndef LOG4CPP_LOG2FILE_LOG2FILE_H
#define LOG4CPP_LOG2FILE_LOG2FILE_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <fstream>

#include "log4cpp/config4log/config4log.h"

namespace log4cpp {
namespace log2file {
    
using log4cpp::config4log::Config4Log;

class Log2File {

public:
    Log2File();

    Log2File(const std::string &log_path);

    Log2File(const Config4Log &config4log);

    ~Log2File();

    void SetLogPath(const std::string &log_path);

    std::string GetLogPath();

    void WriteLog(const std::string &log_info);

    void WriteLogs(std::vector<std::string> &log_infos);

private:

    Config4Log config4log;

}; // class Log2File
}; // namespace log2file
}; // namespace log4cpp 

#endif