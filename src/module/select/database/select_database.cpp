#include "select_database.h"

module::select::select_databases::SelectDataBase::SelectDataBase() {
    this->databases_infos_ptr = std::make_shared<std::vector<std::string>>();
}

module::select::select_databases::SelectDataBase::~SelectDataBase() {
    
}

void module::select::select_databases::SelectDataBase::SetBashPath(const std::string& bashPath) {
    this->bashPath = bashPath;
}

std::string module::select::select_databases::SelectDataBase::GetBashPath() const {
    return this->bashPath;
}

bool module::select::select_databases::SelectDataBase::AddDatabase(const std::string& database) {
    this->databases_infos_ptr->push_back(database);
    return true;
}

std::shared_ptr<std::vector<std::string>> module::select::select_databases::SelectDataBase::GetDatabaseNames() {
    return this->databases_infos_ptr;
}
