#ifndef MODULE_SELECT_SELECT_DATABASE_H
#define MODULE_SELECT_SELECT_DATABASE_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <memory>

#include "core/select/select_dir/select_folder.h"
#include "config/cassel_config/cassel_config.h"
#include "module/config/path/data_path/data_path.h"

namespace module {
namespace select {
namespace select_databases {

using core::select::SelectFolder;
using module::config::path::DataPath;

class SelectDataBase {

public:

    SelectDataBase();

    ~SelectDataBase();

    bool DoSelect();

    bool AddDatabase(const std::string& database);

    std::shared_ptr<std::vector<std::string>> GetDatabaseNames();

private:

    std::shared_ptr<std::vector<std::string>> databases_infos_ptr;

};

}; // namespace select_databases
}; // namespace select
}; // namespace module

#endif // MODULE_SELECT_SELECT_DATABASE_H