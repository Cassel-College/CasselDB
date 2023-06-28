#ifndef LOG4CPP_LOG2FILE_LOG2FILE_H
#define LOG4CPP_LOG2FILE_LOG2FILE_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <fstream>

namespace log4cpp {

namespace log2file {
    
class Log2File {

public:
    Log2File();

    Log2File(const std::string &log_path);

    ~Log2File();

    void SetLogPath(const std::string &log_path);

    std::string GetLogPath();

    void WriteLog(const std::string &log_info);

    void WriteLogs(std::vector<std::string> &log_infos);

private:

    std::string log_path;

}; // class Log2File
}; // namespace log2file
}; // namespace log4cpp 

#endif