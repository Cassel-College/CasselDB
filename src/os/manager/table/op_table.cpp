#include "op_table.h"

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
namespace table {

using log4cpp::log::Log;
using log4cpp::level::Level;
using log4cpp::log_module::LogModule;
using cassel::os::manager::table::OperationTable;

OperationTable::OperationTable() {
    Init();
}

void OperationTable::Init() {
    std::shared_ptr<Log> logMS_ptr = Log::GetLogPtr();
    logMS_ptr->add(LogModule("Default", Level("INFO"), __FILENAME__, __LINE__, "run"));
}

std::shared_ptr<CasselStatus> OperationTable::Do(VecStrPtr operations, CasselStatusPtr status) {
    std::cout << "-----------------------------------" << std::endl;
    for (auto item : *operations) {
        std::cout << "table:" << item << std::endl;
    }
    std::cout << "-----------------------------------" << std::endl;
    return status;
};

bool OperationTable::Create(VecStrPtr operations, CasselStatusPtr status) {
    std::shared_ptr<Log> logMS_ptr = Log::GetLogPtr();
    logMS_ptr->add(LogModule("Default", Level("INFO"), __FILENAME__, __LINE__, "run"));
    return true;
};

bool OperationTable::Select(VecStrPtr operations, CasselStatusPtr status) {
    std::shared_ptr<Log> logMS_ptr = Log::GetLogPtr();
    logMS_ptr->add(LogModule("Default", Level("INFO"), __FILENAME__, __LINE__, "run"));
    return true;
};

bool OperationTable::Delete(VecStrPtr operations, CasselStatusPtr status) {
    std::shared_ptr<Log> logMS_ptr = Log::GetLogPtr();
    logMS_ptr->add(LogModule("Default", Level("INFO"), __FILENAME__, __LINE__, "run"));
    return true;
};

bool OperationTable::Copy(VecStrPtr operations, CasselStatusPtr status) {
    std::shared_ptr<Log> logMS_ptr = Log::GetLogPtr();
    logMS_ptr->add(LogModule("Default", Level("INFO"), __FILENAME__, __LINE__, "run"));
    return true;
};

bool OperationTable::Open(VecStrPtr operations, CasselStatusPtr status) {
    std::shared_ptr<Log> logMS_ptr = Log::GetLogPtr();
    logMS_ptr->add(LogModule("Default", Level("INFO"), __FILENAME__, __LINE__, "run"));
    return true;
};

bool OperationTable::Quit(VecStrPtr operations, CasselStatusPtr status) {
    std::shared_ptr<Log> logMS_ptr = Log::GetLogPtr();
    logMS_ptr->add(LogModule("Default", Level("INFO"), __FILENAME__, __LINE__, "run"));
    return true;
};

}; //namespace table
}; //namespace cassel
}; //namespace os
}; //namespace manager

