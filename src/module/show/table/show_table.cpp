#include "show_table.h"

module::show::ShowTable::ShowTable() {
    this->databaseName = "";
    this->tableList = {};
}

module::show::ShowTable::~ShowTable() {
    this->databaseName = "";
    this->tableList = {};
}

std::string module::show::ShowTable::GetDataBaseName() const {
    return this->databaseName;
}

void module::show::ShowTable::SetDatabaseName(const std::string &databasesName) {
    this->databaseName = databaseName;
}

std::vector<std::string> module::show::ShowTable::GetTableList() const {
    return this->tableList;
}
