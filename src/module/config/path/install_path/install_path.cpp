#include "install_path.h"

#include <iostream>
#include <vector>
#include <core/read/readFile/read_file.h>
#include <core/tools/select_info_from_list/select_info_from_list.h>

using core::read::ReadFile;
using core::tools::SelectInfoFromList;

module::config::path::InstallPath::InstallPath() {
    
}

module::config::path::InstallPath::~InstallPath() {
    
}

std::string module::config::path::InstallPath::GetInstallPath() {
    std::string target = "";
    ReadFile *readFile = new ReadFile();
    readFile->SetPath("/etc/profile");
    readFile->SetInfo();
    std::vector<std::string> file_info_list = readFile->GetInfo();
    file_info_list = SelectInfoFromList::SelectInfo(file_info_list, "#", false);
    file_info_list = SelectInfoFromList::SelectInfo(file_info_list, "CASSELDB_INSTALL_PATH", true);
    if (file_info_list.size() != 0) {
        target = file_info_list[file_info_list.size() - 1];
    }
    return target;
}

bool module::config::path::InstallPath::SoftSec() {
    return true;
}
