#include "select_table.h"

module::select::select_table::SelectTable::SelectTable() {
    this->tables_info_ptr = std::make_shared<std::vector<std::string>>();
}

module::select::select_table::SelectTable::SelectTable(const std::string& path) {
    this->path = path;
    this->tables_info_ptr = std::make_shared<std::vector<std::string>>();
}

module::select::select_table::SelectTable::~SelectTable() {
    
}



