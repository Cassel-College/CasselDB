#include "log2file.h"

log4cpp::log2file::Log2File::Log2File() {
    // std::cout << "Create log2file." << std::endl;
};

log4cpp::log2file::Log2File::Log2File(const std::string &log_path) {
    // std::cout << "Create log2file by log path." << std::endl;
    this->config4log.setLogPath(log_path);
};

log4cpp::log2file::Log2File::Log2File(const Config4Log &config4log) {
    // std::cout << "Create log2file by config." << std::endl;
    this->config4log = config4log;
}

log4cpp::log2file::Log2File::~Log2File() {
    this->SetLogPath("");
};

void log4cpp::log2file::Log2File::SetLogPath(const std::string &log_path) {
    this->config4log.setLogPath(log_path);
}

std::string log4cpp::log2file::Log2File::GetLogPath() {
    return this->config4log.getLogPath();
}

void log4cpp::log2file::Log2File::WriteLog(const std::string &log_info) {

}

void log4cpp::log2file::Log2File::WriteLogs(std::vector<std::string> &log_infos) {
    std::ofstream log_file(this->config4log.getLogPath(), std::ios_base::app);
    if (log_file.is_open()) {
        for (const auto &log : log_infos) {
            log_file << log << std::endl;
        }
        log_file.close();
    } else {
        std::cout << "open log file:" << this->config4log.getLogPath() << " failed." << std::endl;
    }
}