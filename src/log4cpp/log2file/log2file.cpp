#include "log2file.h"

log4cpp::log2file::Log2File::Log2File() {
    this->SetLogPath("");
};

log4cpp::log2file::Log2File::Log2File(const std::string &log_path) {
    this->SetLogPath(log_path);
};


log4cpp::log2file::Log2File::~Log2File() {
    this->SetLogPath("");
};

void log4cpp::log2file::Log2File::SetLogPath(const std::string &log_path) {
    this->log_path = log_path;
}

std::string log4cpp::log2file::Log2File::GetLogPath() {
    return this->log_path;
}

void log4cpp::log2file::Log2File::WriteLog(const std::string &log_info) {

}

void log4cpp::log2file::Log2File::WriteLogs(std::vector<std::string> &log_infos) {

    std::string tmp_log_path = "/opt/CasselDB/logs/log.txt";
    std::ofstream log_file(tmp_log_path, std::ios_base::app);
    std::cout << "-------- Save log to " << tmp_log_path << "---------" << std::endl;
    if (log_file.is_open()) {
        for (const auto &log : log_infos) {
            // std::cout << log << std::endl;
            log_file << log << std::endl;
        }
        log_file.close();
    } else {
        std::cout << "open log file failed." << std::endl;
    }

}