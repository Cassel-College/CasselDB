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
    operation_map.insert(std::pair<std::string, int>("config", 4));
    operation_map.insert(std::pair<std::string, int>("copy",   5));
    operation_map.insert(std::pair<std::string, int>("open",   6));
    operation_map.insert(std::pair<std::string, int>("quit",   7));
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
    } else {
        logMS_ptr->add(LogModule("Default", Level("ERROR"), __FILENAME__, __LINE__, "Unknown operation."));
        return "";
    }

    switch (operation_code) {
        case 1:
            this->Create(operations, status);
            break;
        case 2:
            this->Select(operations, status);
            break;
        case 3:
            this->Delete(operations, status);
            break;
        case 4:
            this->Config(operations, status);
            break;
        case 5:
            this->Copy(operations, status);
            break;
        case 6:
            this->Open(operations, status);
            break;
        case 7:
            this->Quit(operations, status);
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
    return status;
};

bool OperationDefault::Create(std::shared_ptr<std::vector<std::string>> operations,
                              std::shared_ptr<CasselStatus> status) {

    bool create_status = false;
    std::shared_ptr<Log> logMS_ptr = Log::GetLogPtr();
    logMS_ptr->add(LogModule("Default", Level("INFO"), __FILENAME__, __LINE__, "run create operation in default."));

    if (operations->size() == 2) {
        std::string database_name = operations->at(1);
        std::cout << "create database_name:" << database_name << std::endl;


        logMS_ptr->add(LogModule("Default", Level("INFO"), __FILENAME__, __LINE__, "create operation in default."));
        create_status = true;
    } else {
        logMS_ptr->add(LogModule("Default", Level("ERROR"), __FILENAME__, __LINE__, "create operation in default."));
    }

    logMS_ptr->add(LogModule("Default", Level("INFO"), __FILENAME__, __LINE__, "run create operation in default over."));
    return create_status;
};

bool OperationDefault::Select(std::shared_ptr<std::vector<std::string>> operations,
                              std::shared_ptr<CasselStatus> status) {

    std::shared_ptr<Log> logMS_ptr = Log::GetLogPtr();
    logMS_ptr->add(LogModule("Default", Level("INFO"), __FILENAME__, __LINE__, "run"));

    if (operations->size() == 2) {
        std::string database_name = operations->at(1);
        logMS_ptr->add(LogModule("Default", Level("INFO"), __FILENAME__, __LINE__, "select operation in default."));
    } else {
        logMS_ptr->add(LogModule("Default", Level("ERROR"), __FILENAME__, __LINE__, "select operation in default."));
    }

    std::cout << "Select .... " << std::endl;
    return true;
};

bool OperationDefault::Delete(std::shared_ptr<std::vector<std::string>> operations,
                              std::shared_ptr<CasselStatus> status) {
                                
    std::shared_ptr<Log> logMS_ptr = Log::GetLogPtr();
    logMS_ptr->add(LogModule("Default", Level("INFO"), __FILENAME__, __LINE__, "run"));

    if (operations->size() == 2) {
        std::string database_name = operations->at(1);
        
        logMS_ptr->add(LogModule("Default", Level("INFO"), __FILENAME__, __LINE__, "delete operation in default."));
    } else {
        logMS_ptr->add(LogModule("Default", Level("ERROR"), __FILENAME__, __LINE__, "delete operation in default."));
    }

    std::cout << "Delete .... " << std::endl;
    return true;
};

bool OperationDefault::Config(std::shared_ptr<std::vector<std::string>> operations,
                              std::shared_ptr<CasselStatus> status) {
                                
    std::shared_ptr<Log> logMS_ptr = Log::GetLogPtr();
    logMS_ptr->add(LogModule("Default", Level("INFO"), __FILENAME__, __LINE__, "run"));

    if (operations->size() == 1) {
        logMS_ptr->add(LogModule("Default", Level("INFO"), __FILENAME__, __LINE__, "config operation in default."));
        status->SetStatus(CasselManagerStatus::CONFIG);
    } else {
        logMS_ptr->add(LogModule("Default", Level("ERROR"), __FILENAME__, __LINE__, "config operation in default."));
    }

    std::cout << "Config .... " << std::endl;
    return true;
};

bool OperationDefault::Copy(std::shared_ptr<std::vector<std::string>> operations,
                            std::shared_ptr<CasselStatus> status) {

    std::shared_ptr<Log> logMS_ptr = Log::GetLogPtr();
    logMS_ptr->add(LogModule("Default", Level("INFO"), __FILENAME__, __LINE__, "run"));

    if (operations->size() == 3) {
        std::string old_database_name = operations->at(1);
        std::string new_database_name = operations->at(2);
        // this->Copy();
        logMS_ptr->add(LogModule("Default", Level("INFO"), __FILENAME__, __LINE__, "copy operation in default."));
    } else {
        logMS_ptr->add(LogModule("Default", Level("ERROR"), __FILENAME__, __LINE__, "copy operation in default."));
    }

    std::cout << "Copy .... " << std::endl;
    return true;
};

bool OperationDefault::Open(std::shared_ptr<std::vector<std::string>> operations,
                            std::shared_ptr<CasselStatus> status) {

    std::shared_ptr<Log> logMS_ptr = Log::GetLogPtr();
    logMS_ptr->add(LogModule("Default", Level("INFO"), __FILENAME__, __LINE__, "run"));
    if (operations->size() == 2) {
        std::string database_name = operations->at(1);
        // this->Open();
        logMS_ptr->add(LogModule("Default", Level("INFO"), __FILENAME__, __LINE__, "open operation in default."));
    } else {
        logMS_ptr->add(LogModule("Default", Level("ERROR"), __FILENAME__, __LINE__, "open operation in default."));
    }
    std::cout << "Open .... " << std::endl;
    return true;
};

bool OperationDefault::Other(std::shared_ptr<std::vector<std::string>> operations,
                             std::shared_ptr<CasselStatus> status) {

    std::shared_ptr<Log> logMS_ptr = Log::GetLogPtr();
    logMS_ptr->add(LogModule("Default", Level("INFO"), __FILENAME__, __LINE__, "run"));
    std::string operation_info = this->OperationStrBuff(operations);
    logMS_ptr->add(LogModule("other operation: " + operation_info, Level("INFO"), __FILENAME__, __LINE__, "run"));
    return true;
};


bool OperationDefault::Quit(std::shared_ptr<std::vector<std::string>> operations,
                            std::shared_ptr<CasselStatus> status) {

    std::shared_ptr<Log> logMS_ptr = Log::GetLogPtr();
    logMS_ptr->add(LogModule("Default", Level("INFO"), __FILENAME__, __LINE__, "quit Cassel DB operation in default."));
    status->SetStatus(CasselManagerStatus::QUIT);
    return true;
};

}; //namespace def
}; //namespace cassel
}; //namespace os
}; //namespace manager

