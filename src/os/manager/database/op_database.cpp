#include "op_database.h"

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
namespace database {

using log4cpp::log::Log;
using log4cpp::level::Level;
using log4cpp::log_module::LogModule;
using cassel::os::manager::database::OperationDatabase;

OperationDatabase::OperationDatabase() {
    Init();
    InitOperation();
}

void OperationDatabase::Init() {
    std::shared_ptr<Log> logMS_ptr = Log::GetLogPtr();
    logMS_ptr->add(LogModule("Default", Level("INFO"), __FILENAME__, __LINE__, "run"));
}

void OperationDatabase::InitOperation() {
    operation_map.insert(std::pair<std::string, int>("create", 1));
    operation_map.insert(std::pair<std::string, int>("select", 2));
    operation_map.insert(std::pair<std::string, int>("delete", 3));
    operation_map.insert(std::pair<std::string, int>("copy",   5));
    operation_map.insert(std::pair<std::string, int>("open",   6));
    operation_map.insert(std::pair<std::string, int>("status", 7));
    operation_map.insert(std::pair<std::string, int>("quit",   8));
}

std::string OperationDatabase::OperationToParameter(VecStrPtr operations, CasselStatusPtr status) {
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
        case 5:
            this->Copy(operations, status);
            break;
        case 6:
            this->Open(operations, status);
            break;
        case 7:
            this->Status(operations, status);
            break;
        case 8:
            this->Quit(operations, status);
            break;
        default:
            logMS_ptr->add(LogModule("Default", Level("INFO"), __FILENAME__, __LINE__, "Unknown operation."));
            break;
    }
    return "";
}

std::shared_ptr<CasselStatus> OperationDatabase::Do(VecStrPtr operations, CasselStatusPtr status) {
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

bool OperationDatabase::Create(VecStrPtr operations, CasselStatusPtr status) {
    
    bool create_status = false;
    std::shared_ptr<Log> logMS_ptr = Log::GetLogPtr();
    logMS_ptr->add(LogModule("Default", Level("INFO"), __FILENAME__, __LINE__, "run create operation in database."));

    if (operations->size() == 2) {
        std::string database_name = status->GetDatabaseName();
        std::string table_name = operations->at(1);
        std::cout << "create table name:" << table_name << std::endl;
        table_name = table_name + "_cassel.db";
        std::shared_ptr<CasselConfig> cassel_config_ptr = CasselConfig::GetCasselConfigPtr();

        std::shared_ptr<CreateTable> create_table_ptr = std::make_shared<CreateTable>();
        create_table_ptr->SetDatabaseName(database_name);
        create_table_ptr->SetTableName(table_name);
        create_table_ptr->CreateTableCore();

        logMS_ptr->add(LogModule("Default", Level("INFO"), __FILENAME__, __LINE__, "create operation in database."));
        create_status = true;
    } else {
        logMS_ptr->add(LogModule("Default", Level("ERROR"), __FILENAME__, __LINE__, "create operation in database."));
    }

    logMS_ptr->add(LogModule("Default", Level("INFO"), __FILENAME__, __LINE__, "run create operation in database over."));
    return create_status;
};

bool OperationDatabase::Select(VecStrPtr operations, CasselStatusPtr status) {
    bool select_status = false;
    std::shared_ptr<Log> logMS_ptr = Log::GetLogPtr();
    std::string databases_name = status->GetDatabaseName();
    logMS_ptr->add(LogModule("select tables in database " + databases_name, Level("INFO"), __FILENAME__, __LINE__, "os"));

    if (operations->size() == 1) {
        logMS_ptr->add(LogModule("select table info in default.", Level("INFO"), __FILENAME__, __LINE__, "os"));

        std::shared_ptr<CasselConfig> cassel_config_ptr = CasselConfig::GetCasselConfigPtr();
        std::string cassel_db_path = cassel_config_ptr->GetConfigByName("data_path");

        SelectTablePrt select_table_ptr = std::make_shared<SelectTable>(cassel_db_path, databases_name);
        select_table_ptr->DoSelectTable();
        VecStrPtr table_infos = select_table_ptr->GetTableInfos();

        std::shared_ptr<SimpleUI> simple_ui_ptr = std::make_shared<SimpleUI>();
        VecStrPtr taregt_infos = simple_ui_ptr->GenDB(table_infos);
        simple_ui_ptr->Show(taregt_infos);
        select_status = true;
    } else {
        logMS_ptr->add(LogModule("operation error.", Level("ERROR"), __FILENAME__, __LINE__, "os"));
    }
    logMS_ptr->add(LogModule("Select table in database " + databases_name + " over.", Level("INFO"), __FILENAME__, __LINE__, "os"));
    return select_status;
};

bool OperationDatabase::Delete(VecStrPtr operations, CasselStatusPtr status) {
    std::shared_ptr<Log> logMS_ptr = Log::GetLogPtr();
    logMS_ptr->add(LogModule("Default", Level("INFO"), __FILENAME__, __LINE__, "run"));
    return true;
};

bool OperationDatabase::Status(VecStrPtr operations, CasselStatusPtr status) {
    std::shared_ptr<Log> logMS_ptr = Log::GetLogPtr();
    logMS_ptr->add(LogModule("Default", Level("INFO"), __FILENAME__, __LINE__, "run"));
    return true;
};

bool OperationDatabase::Copy(VecStrPtr operations, CasselStatusPtr status) {
    std::shared_ptr<Log> logMS_ptr = Log::GetLogPtr();
    logMS_ptr->add(LogModule("Default", Level("INFO"), __FILENAME__, __LINE__, "run"));
    return true;
};

bool OperationDatabase::Open(VecStrPtr operations, CasselStatusPtr status) {
    std::shared_ptr<Log> logMS_ptr = Log::GetLogPtr();
    logMS_ptr->add(LogModule("Default", Level("INFO"), __FILENAME__, __LINE__, "run"));
    return true;
};

bool OperationDatabase::Quit(VecStrPtr operations, CasselStatusPtr status) {
    std::shared_ptr<Log> logMS_ptr = Log::GetLogPtr();
    logMS_ptr->add(LogModule("Default", Level("INFO"), __FILENAME__, __LINE__, "run"));
    if (operations->size() == 1) {
        logMS_ptr->add(LogModule("Default", Level("INFO"), __FILENAME__, __LINE__, "Quit databses"));
        status->SetStatus(CasselManagerStatus::DEFAULT);
        status->SetDatabaseName("");
    } else {
        logMS_ptr->add(LogModule("Default", Level("ERROR"), __FILENAME__, __LINE__, "Quit databases."));
    }
    std::cout << "Open .... " << std::endl;
    return true;
};

}; //namespace database
}; //namespace cassel
}; //namespace os
}; //namespace manager
