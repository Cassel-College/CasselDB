#include "select_table.h"

module::select::select_table::SelectTable::SelectTable() {
    this->tables_info_ptr = std::make_shared<std::vector<std::string>>();
}

module::select::select_table::SelectTable::SelectTable(const std::string& path) {
    this->path = path;
    this->tables_info_ptr = std::make_shared<std::vector<std::string>>();
}

module::select::select_table::SelectTable::SelectTable(const std::string& path, const std::string& database_info) {
    this->path = path;
    this->database_info = database_info;
    this->tables_info_ptr = std::make_shared<std::vector<std::string>>();
}


module::select::select_table::SelectTable::~SelectTable() {
    
}

bool module::select::select_table::SelectTable::DoSelectTable() {
    std::cout << "DoSelectTable" << std::endl;
    std::shared_ptr<log4cpp::log::Log> logMS_ptr = Log::GetLogPtr();
    logMS_ptr->add(LogModule("Begin select table info.", Level("DEBUG"), __FILE__, __LINE__, "os"));

    std::string database_path = this->path + "/" + this->database_info;

    std::vector<std::string> table_names = SelectFolder::GetFileListByPath(database_path);

    for (auto& table_name : table_names) {
        this->tables_info_ptr->push_back(table_name);
    }
    
}

std::shared_ptr<std::vector<std::string>> module::select::select_table::SelectTable::GetTableInfos() {
    return this->tables_info_ptr;
}
