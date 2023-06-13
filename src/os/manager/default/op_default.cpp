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
        
    operation_map.insert(std::pair<std::string, int>("create", 1));
    operation_map.insert(std::pair<std::string, int>("select", 2));
    operation_map.insert(std::pair<std::string, int>("delete", 3));
    operation_map.insert(std::pair<std::string, int>("copy",   4));
    operation_map.insert(std::pair<std::string, int>("open",   5));
    operation_map.insert(std::pair<std::string, int>("quit",   6));
}


std::string OperationDefault::OperationToParameter(std::shared_ptr<std::vector<std::string>> operations,
                                                   std::shared_ptr<CasselStatus> status) {

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
    }
    std::cout << "operation_code:" << operation_code << std::endl;
    switch (operation_code) {
        case 1:
            if (operations->size() == 2) {
                std::string database_name = operations->at(1);
                this->Create();
                logMS_ptr->add(LogModule("Default", Level("INFO"), __FILENAME__, __LINE__, "create operation in default."));
            } else {
                logMS_ptr->add(LogModule("Default", Level("ERROR"), __FILENAME__, __LINE__, "create operation in default."));
            }
            break;
        case 2:
            if (operations->size() == 2) {
                std::string database_name = operations->at(1);
                this->Create();
                logMS_ptr->add(LogModule("Default", Level("INFO"), __FILENAME__, __LINE__, "select operation in default."));
            } else {
                logMS_ptr->add(LogModule("Default", Level("ERROR"), __FILENAME__, __LINE__, "select operation in default."));
            }
            break;
        case 3:
            if (operations->size() == 2) {
                std::string database_name = operations->at(1);
                this->Delete();
                logMS_ptr->add(LogModule("Default", Level("INFO"), __FILENAME__, __LINE__, "delete operation in default."));
            } else {
                logMS_ptr->add(LogModule("Default", Level("ERROR"), __FILENAME__, __LINE__, "delete operation in default."));
            }
            break;
        case 4:
            if (operations->size() == 3) {
                std::string old_database_name = operations->at(1);
                std::string new_database_name = operations->at(2);
                this->Copy();
                logMS_ptr->add(LogModule("Default", Level("INFO"), __FILENAME__, __LINE__, "copy operation in default."));
            } else {
                logMS_ptr->add(LogModule("Default", Level("ERROR"), __FILENAME__, __LINE__, "copy operation in default."));
            }
            break;
        case 5:
            if (operations->size() == 2) {
                std::string database_name = operations->at(1);
                this->Open();
                logMS_ptr->add(LogModule("Default", Level("INFO"), __FILENAME__, __LINE__, "open operation in default."));
            } else {
                logMS_ptr->add(LogModule("Default", Level("ERROR"), __FILENAME__, __LINE__, "open operation in default."));
            }
            
            break;
        case 6:
            logMS_ptr->add(LogModule("Default", Level("INFO"), __FILENAME__, __LINE__, "quit operation in default."));
            status->SetStatus(CasselManagerStatus::QUIT);
            break;
        default:
            logMS_ptr->add(LogModule("Default", Level("INFO"), __FILENAME__, __LINE__, "Unknown operation."));
            break;
    }
    return "";
}

std::shared_ptr<CasselStatus> OperationDefault::Do(std::shared_ptr<std::vector<std::string>> operations,
                                                   std::shared_ptr<CasselStatus> status) {
    std::shared_ptr<Log> logMS_ptr = Log::GetLogPtr();
    logMS_ptr->add(LogModule("Default", Level("INFO"), __FILENAME__, __LINE__, "run"));

    std::string operation = "";
    if (int(operations->size()) > 0) {
        std::string code = this->OperationToParameter(operations, status);
        
    } else {
        std::cout << "operation is empty" << std::endl;
        logMS_ptr->add(LogModule("Default", Level("ERROR"), __FILENAME__, __LINE__, "no operation."));
    }
    std::cout << "-----------------------------------" << std::endl;


    // this->Create();
    // this->Select();
    // this->Delete();
    // this->Copy();
    // this->Open();
    // this->Quit();
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

