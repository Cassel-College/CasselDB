#include "show_table.h"

module::show::table::ShowTable::ShowTable() 
{
    this->databaseName = "";
    this->tableList = {};
}

module::show::table::ShowTable::~ShowTable() 
{
    this->databaseName = "";
    this->tableList = {};
}

std::string module::show::table::ShowTable::GetDataBaseName() const 
{
    return this->databaseName;
}

void module::show::table::ShowTable::SetDatabaseName(const std::string &databasesName) 
{
    this->databaseName = databaseName;
}

std::vector<std::string> module::show::table::ShowTable::GetTableList() const 
{
    return this->tableList;
}