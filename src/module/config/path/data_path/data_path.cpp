#include "data_path.h"
#include <iostream>
#include <vector>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <core/read/readFile/read_file.h>
#include <core/tools/select_info_from_list/select_info_from_list.h>

using core::read::ReadFile;
using core::tools::SelectInfoFromList;

module::config::path::DataPath::DataPath() {
    
}

module::config::path::DataPath::~DataPath() {
    
}

std::string module::config::path::DataPath::GetDataPath() {
    std::string target = "";
    ReadFile *readFile = new ReadFile();
    readFile->SetPath("/etc/profile");
    readFile->SetInfo();
    std::vector<std::string> file_info_list = readFile->GetInfo();
    file_info_list = SelectInfoFromList::SelectInfo(file_info_list, "#", false);
    file_info_list = SelectInfoFromList::SelectInfo(file_info_list, "CASSELDB_DATA_PATH", true);
    if (file_info_list.size() != 0) {
        target = file_info_list[file_info_list.size() - 1];
    }
    if (target.find('=') != std::string::npos) {
        target = target.substr(target.find('=') + 1);
    } else {
        target = "";
    }
    std::cout << target << "----------------------------------" << std::endl;
    return target;
}

bool module::config::path::DataPath::DataSec() {
    std::string dataPath = DataPath::GetDataPath();
    bool key = false;
    if (dataPath.length() > 2048 || dataPath.length() == 0) {
        return key;
    }
    // Liunx create folder
    int returnKey = access(dataPath.c_str(), F_OK);
    if (returnKey == 0) {
        key = true;
    } else {
        key = false;
    }
    return key;
}
