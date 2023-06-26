#include "create_table.h"

using module::create::CreateTableStatus;

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

/**
 * @brief Destructor for the SimpleUI class from the cassel::os::ui namespace. 
 * 
 * @return true 
 * @return false 
 * @version 0.1
 * @author liupeng (liupeng.0@outlook.com)
 * @date 2023-06-25
 * @copyright Copyright (c) 2023
 * @return true 
 * @return false 
 */
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

/**
 * @brief Create Table.
 * 
 * @version 0.1
 * @author liupeng (liupeng.0@outlook.com)
 * @date 2023-06-25
 * @copyright Copyright (c) 2023
 */
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
    // std::shared_ptr<CreateFile> create_file_ptr = std::make_shared<CreateFile>();

    DataPath *dataPath = new DataPath();
    std::string tablePath = dataPath->GetDataPath() + "/" + this->GetDatabaseName();
    createFile->SetPath(tablePath);

    std::cout << " Table path: " << tablePath << std::endl;
    std::cout << " Table name: " << this->tableName << std::endl;
    createFile->SetFileName(this->tableName);
    createFile->DoCreateFile();
    return;
}
