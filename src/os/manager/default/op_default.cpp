#include "op_default.h"

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
namespace def {

using log4cpp::log::Log;
using log4cpp::level::Level;
using log4cpp::log_module::LogModule;

using cassel::os::manager::def::OperationDefault;

OperationDefault::OperationDefault() {
    Init();
}

void OperationDefault::Init() {
    std::shared_ptr<Log> logMS_ptr = Log::GetLogPtr();
    logMS_ptr->add(LogModule("Default", Level("INFO"), __FILENAME__, __LINE__, "run"));
    this->InitOperation();
}

void OperationDefault::InitOperation() {
    this->operation_names.clear();
    this->operation_names.insert("create");
    this->operation_names.insert("select");
    this->operation_names.insert("delete");
    this->operation_names.insert("copy");
    this->operation_names.insert("open");
    this->operation_names.insert("quit");
}

std::shared_ptr<CasselStatus> OperationDefault::Do(std::shared_ptr<std::vector<std::string>> operations,
                                                   std::shared_ptr<CasselStatus> status) {
    std::shared_ptr<Log> logMS_ptr = Log::GetLogPtr();
    logMS_ptr->add(LogModule("Default", Level("INFO"), __FILENAME__, __LINE__, "run"));

    std::string operation = "";
    this->Create();
    this->Select();
    this->Delete();
    this->Copy();
    this->Open();
    this->Quit();
    if (int(operations->size()) > 0) {
        operation = operations->at(0);
        std::cout << operation << std::endl;
        if (this->operation_names.find(operation) == this->operation_names.end()) {
            this->Other(operations);
        } else {
            std::cout << "operation " << operation << " is not supported" << std::endl;
        }
    } else {
        std::cout << "operation is empty" << std::endl;
        logMS_ptr->add(LogModule("Default", Level("ERROR"), __FILENAME__, __LINE__, "no operation."));
    }
    std::cout << "-----------------------------------" << std::endl;
    return status;
};

bool OperationDefault::Create() {
    std::shared_ptr<Log> logMS_ptr = Log::GetLogPtr();
    logMS_ptr->add(LogModule("Default", Level("INFO"), __FILENAME__, __LINE__, "run"));
    std::cout << "Create .... " << std::endl;
    return true;
};

bool OperationDefault::Select() {
    std::shared_ptr<Log> logMS_ptr = Log::GetLogPtr();
    logMS_ptr->add(LogModule("Default", Level("INFO"), __FILENAME__, __LINE__, "run"));
    std::cout << "Select .... " << std::endl;
    return true;
};

bool OperationDefault::Delete() {
    std::shared_ptr<Log> logMS_ptr = Log::GetLogPtr();
    logMS_ptr->add(LogModule("Default", Level("INFO"), __FILENAME__, __LINE__, "run"));
    std::cout << "Delete .... " << std::endl;
    return true;
};

bool OperationDefault::Copy() {
    std::shared_ptr<Log> logMS_ptr = Log::GetLogPtr();
    logMS_ptr->add(LogModule("Default", Level("INFO"), __FILENAME__, __LINE__, "run"));
    std::cout << "Copy .... " << std::endl;
    return true;
};

bool OperationDefault::Open() {
    std::shared_ptr<Log> logMS_ptr = Log::GetLogPtr();
    logMS_ptr->add(LogModule("Default", Level("INFO"), __FILENAME__, __LINE__, "run"));
    std::cout << "Open .... " << std::endl;
    return true;
};

bool OperationDefault::Other(std::shared_ptr<std::vector<std::string>> operations) {
    std::shared_ptr<Log> logMS_ptr = Log::GetLogPtr();
    logMS_ptr->add(LogModule("Default", Level("INFO"), __FILENAME__, __LINE__, "run"));
    std::string operation_info = this->OperationStrBuff(operations);
    logMS_ptr->add(LogModule("other operation: " + operation_info, Level("INFO"), __FILENAME__, __LINE__, "run"));
    return true;
};


bool OperationDefault::Quit() {
    std::shared_ptr<Log> logMS_ptr = Log::GetLogPtr();
    logMS_ptr->add(LogModule("Default", Level("INFO"), __FILENAME__, __LINE__, "run"));
    std::cout << "Quit .... " << std::endl;
    return true;
};

}; //namespace def
}; //namespace cassel
}; //namespace os
}; //namespace manager

