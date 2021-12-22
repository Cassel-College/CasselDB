#include "show_database.h"
#include <module/config/path/data_path/data_path.h>
#include <core/select/select_dir/select_folder.h>
#include <dirent.h>

using module::config::path::DataPath;
using core::select::SelectFolder;

module::show::database::ShowDatabase::ShowDatabase() {
    this->dbNameList = {};
    DataPath *dataPath = new DataPath();
    if (DataPath::DataSec()) {
        this->SetDataPath(DataPath::GetDataPath());
    } else {
        this->SetDataPath("");
    }
}

module::show::database::ShowDatabase::~ShowDatabase() {
    this->dataPath = "";
}

void module::show::database::ShowDatabase::SetDataPath(const std::string &path) {
    this->dataPath = path;
}

std::string module::show::database::ShowDatabase::GetDataPath() const {
    return this->dataPath;
}

void module::show::database::ShowDatabase::SetDBNameList() {
    if (0 == this->GetDataPath().compare("")) {
        return;
    }
    this->dbNameList = SelectFolder::GetFolderListByPath(this->GetDataPath());
}

std::vector<std::string> module::show::database::ShowDatabase::GetDBNamelist() const {
    return this->dbNameList;
}