#include "create_table.h"

using module::create::CreateTableStatus;


module::create::CreateTable::CreateTable() {
    this->databaseName = "";
    this->tableName = "";
    this->status = CreateTableStatus::INIT;
}

module::create::CreateTable::~CreateTable() {
    this->databaseName = "";
    this->tableName = "";
    this->status = CreateTableStatus::INIT;
}

void module::create::CreateTable::SetTableName(const std::string& tableName) {
    this->tableName = tableName;
}

std::string module::create::CreateTable::GetTableName() const {
    return this->tableName;
}

void module::create::CreateTable::SetDatabaseName(const std::string& databaseName) {
    this->databaseName = databaseName;
}

std::string module::create::CreateTable::GetDatabaseName() const {
    return this->databaseName;
}

void module::create::CreateTable::SetStatus(CreateTableStatus status) {
    this->status = status;
}

CreateTableStatus module::create::CreateTable::Getstatus() {
    return this->status;
}

bool module::create::CreateTable::CheckEnvironment() {
    bool environmentOK = false;

    return environmentOK;
}

bool module::create::CreateTable::HasSameTableInDatabase() {
    bool hasTable = true;

    return hasTable;
}

void module::create::CreateTable::CraeteTable() {
    
    return;
}
