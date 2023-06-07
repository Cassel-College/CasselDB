#include "op_config.h"

/**
 * @brief 
 * 
 * @version 0.1
 * @author liupeng (liupeng.0@outlook.com)
 * @date 2023-03-02
 * @copyright Copyright (c) 2023
 */

namespace cassel {
namespace os {
namespace manager {
namespace config {

using log4cpp::log::Log;
using log4cpp::level::Level;
using log4cpp::log_module::LogModule;
using cassel::os::manager::config::OperationConfig;

OperationConfig::OperationConfig() {
    Init();
}

void OperationConfig::Init() {
    std::shared_ptr<Log> logMS_ptr = Log::GetLogPtr();
    logMS_ptr->add(LogModule("Default", Level("INFO"), __FILENAME__, __LINE__, "run"));
}

CasselStatus Do(std::shared_ptr<std::vector<std::string>> operations, CasselStatus status) {
    std::cout << "-----------------------------------" << std::endl;
    for (auto item : *operations) {
        std::cout << "config:" << item << std::endl;
    }
    std::cout << "-----------------------------------" << std::endl;
    return status;
};

bool OperationConfig::Create() {
    std::shared_ptr<Log> logMS_ptr = Log::GetLogPtr();
    logMS_ptr->add(LogModule("Default", Level("INFO"), __FILENAME__, __LINE__, "run"));
    return true;
};

bool OperationConfig::Select() {
    std::shared_ptr<Log> logMS_ptr = Log::GetLogPtr();
    logMS_ptr->add(LogModule("Default", Level("INFO"), __FILENAME__, __LINE__, "run"));
    return true;
};

bool OperationConfig::Delete() {
    std::shared_ptr<Log> logMS_ptr = Log::GetLogPtr();
    logMS_ptr->add(LogModule("Default", Level("INFO"), __FILENAME__, __LINE__, "run"));
    return true;
};

bool OperationConfig::Copy() {
    std::shared_ptr<Log> logMS_ptr = Log::GetLogPtr();
    logMS_ptr->add(LogModule("Default", Level("INFO"), __FILENAME__, __LINE__, "run"));
    return true;
};

bool OperationConfig::Open() {
    std::shared_ptr<Log> logMS_ptr = Log::GetLogPtr();
    logMS_ptr->add(LogModule("Default", Level("INFO"), __FILENAME__, __LINE__, "run"));
    return true;
};

bool OperationConfig::Quit() {
    std::shared_ptr<Log> logMS_ptr = Log::GetLogPtr();
    logMS_ptr->add(LogModule("Default", Level("INFO"), __FILENAME__, __LINE__, "run"));
    return true;
};

}; //namespace config
}; //namespace cassel
}; //namespace os
}; //namespace manager

