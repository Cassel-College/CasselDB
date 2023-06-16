#ifndef MODULE_SELECT_SELECT_TABLE_H
#define MODULE_SELECT_SELECT_TABLE_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <memory>

#include <core/select/select_dir/select_folder.h>


namespace module {
namespace select {
namespace select_table {
    
class SelectTable {

public:

    SelectTable();

    SelectTable(const std::string& path);

    ~SelectTable();

private:

    std::string path;

    std::shared_ptr<std::vector<std::string>> tables_info_ptr;


}; // class SelectTable

}; // namespace select_table
}; // namespace select
}; // namespace module
