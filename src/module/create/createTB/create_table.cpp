#include "create_table.h"
#include <algorithm>
#include <module/show/table/show_table.h>
#include <module/show/database/show_database.h>
#include <module/config/path/data_path/data_path.h>
#include <core/create/createFile/create_file.h>


using module::create::CreateTableStatus;
using module::show::table::ShowTable;
using module::show::database::ShowDatabase;
using module::config::path::DataPath;
using core::create::CreateFile;

module::create::CreateTable::CreateTable() 
{
    this->databaseName = "";
    this->tableName = "";
    this->status = CreateTableStatus::INIT;
}

module::create::CreateTable::~CreateTable() 
{
    this->databaseName = "";
    this->tableName = "";
    this->status = CreateTableStatus::INIT;
}

void module::create::CreateTable::SetTableName(const std::string& tableName) 
{
    this->tableName = tableName;
}

std::string module::create::CreateTable::GetTableName() const
{
    return this->tableName;
}

void module::create::CreateTable::SetDatabaseName(const std::string& databaseName) 
{
    this->databaseName = databaseName;
}

std::string module::create::CreateTable::GetDatabaseName() const
{
    return this->databaseName;
}

void module::create::CreateTable::SetStatus(CreateTableStatus status) 
{
    this->status = status;
}

CreateTableStatus module::create::CreateTable::Getstatus()
{
    return this->status;
}

bool module::create::CreateTable::CheckEnvironment()
{
    bool environmentOK = false;
    DataPath *dataPath = new DataPath();
    if (dataPath->DataSec()) {
        if (this->HasDatabase()) {
            environmentOK = true;
        }
    }
    return environmentOK;
}

bool module::create::CreateTable::HasSameTableInDatabase() const
{
    bool hasTable = true;
    ShowTable *showTable = new ShowTable();
    showTable->SetDatabaseName(this->GetDatabaseName());
    std::vector<std::string> tableNameList = showTable->GetTableList();
    std::vector<std::string>::iterator iter = std::find(tableNameList.begin(), tableNameList.end(), this->tableName);
    if (iter != tableNameList.end()) {
        hasTable = false;
    }
    return hasTable;
}

bool module::create::CreateTable::HasDatabase() const {
    bool hasDB = true;
    ShowDatabase *showDatabase = new ShowDatabase();
    std::vector<std::string> dbNameList = showDatabase->GetDBNamelist();
    std::vector<std::string>::iterator iter = std::find(dbNameList.begin(), dbNameList.end(), this->databaseName);
    if (iter != dbNameList.end()) {
        hasDB = false;
    }
    return hasDB;
}

void module::create::CreateTable::CreateTableCore() 
{
    if (this->CheckEnvironment()) {
        this->SetStatus(CreateTableStatus::ERROR_TABLE_NAME);
    }
    if (this->HasDatabase()) {
        this->SetStatus(CreateTableStatus::NO_DATABASE);
    }
    if (this->HasSameTableInDatabase()) {
        this->SetStatus(CreateTableStatus::HAS_SAME_TABLE);
    }
    CreateFile *createFile = new CreateFile();
    DataPath *dataPath = new DataPath();
    std::string tablePath = dataPath->GetDataPath() + "/" + this->GetDatabaseName();
    createFile->SetPath(tablePath);
    createFile->SetFileName(this->tableName);
    createFile->DoCreateFile();
    return;
}
