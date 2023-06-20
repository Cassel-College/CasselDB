#include "select_database.h"

module::select::select_databases::SelectDataBase::SelectDataBase() {
    this->databases_infos_ptr = std::make_shared<std::vector<std::string>>();
}

module::select::select_databases::SelectDataBase::~SelectDataBase() {
    
}

bool module::select::select_databases::SelectDataBase::AddDatabase(const std::string& database) {
    this->databases_infos_ptr->push_back(database);
    return true;
}

bool module::select::select_databases::SelectDataBase::DoSelect() {

    bool select_status = false;
    std::shared_ptr<DataPath> data_path_ptr = std::make_shared<DataPath>();
    std::string database_bash_path = data_path_ptr->GetDataPath();

    std::shared_ptr<SelectFolder> select_folder_ptr = std::make_shared<SelectFolder>();
    std::vector<std::string> folder_names = select_folder_ptr->GetFolderListByPath(database_bash_path);

    for (std::string &folder_name : folder_names) {
        this->AddDatabase(folder_name);
    }
    return select_status;
}

std::shared_ptr<std::vector<std::string>> module::select::select_databases::SelectDataBase::GetDatabaseNames() {
    return this->databases_infos_ptr;
}
