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
    this->InitOperation();
    std::shared_ptr<Log> logMS_ptr = Log::GetLogPtr();
    logMS_ptr->add(LogModule("Default", Level("INFO"), __FILENAME__, __LINE__, "run"));
}

void OperationConfig::InitOperation() {
    operation_map.insert(std::pair<std::string, int>("quit", 1));
}

std::string OperationConfig::OperationToParameter(VecStrPtr operations, CasselStatusPtr status) {
    std::shared_ptr<Log> logMS_ptr = Log::GetLogPtr();
    if (operations->size() == 0) {
        logMS_ptr->add(LogModule("Default", Level("INFO"), __FILENAME__, __LINE__, "Empty operations."));
        return "";
    }
    std::string operation = operations->at(0);
    std::cout << "operation:" << operation << std::endl;
    std::map<std::string, int>::iterator operation_iter; 
    operation_iter = this->operation_map.find(operation);
    int operation_code = -1;
    if(operation_iter != this->operation_map.end()) {
        operation_code = operation_iter->second;
    } else {
        logMS_ptr->add(LogModule("Default", Level("ERROR"), __FILENAME__, __LINE__, "Unknown operation."));
        return "";
    }

    switch (operation_code) {
        case 1:
            this->Quit(operations, status);
            break;
        default:
            logMS_ptr->add(LogModule("Default", Level("INFO"), __FILENAME__, __LINE__, "Unknown operation."));
            break;
    }
    return "";
};

std::shared_ptr<CasselStatus> OperationConfig::Do(VecStrPtr operations, CasselStatusPtr status) {
    std::shared_ptr<Log> logMS_ptr = Log::GetLogPtr();
    logMS_ptr->add(LogModule("Default do some operation.", Level("INFO"), __FILENAME__, __LINE__, "run"));
    std::string operation = "";
    if (int(operations->size()) > 0) {
        std::string code = this->OperationToParameter(operations, status);
    } else {
        logMS_ptr->add(LogModule("Default: no operation.", Level("ERROR"), __FILENAME__, __LINE__, "run"));
    }
    return status;
};

bool OperationConfig::Quit(VecStrPtr operations, CasselStatusPtr status) {
    std::shared_ptr<Log> logMS_ptr = Log::GetLogPtr();
    logMS_ptr->add(LogModule("Default", Level("INFO"), __FILENAME__, __LINE__, "run"));
    if (operations->size() == 1) {
        logMS_ptr->add(LogModule("Default", Level("INFO"), __FILENAME__, __LINE__, "Quit config."));
        status->SetStatus(CasselManagerStatus::DEFAULT);
        status->SetDatabaseName("");
    } else {
        logMS_ptr->add(LogModule("Default", Level("ERROR"), __FILENAME__, __LINE__, "Quit config."));
    }
    std::cout << "Quit .... " << std::endl;
    return true;
};

}; //namespace config
}; //namespace cassel
}; //namespace os
}; //namespace manager

