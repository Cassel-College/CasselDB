#include "install_path.h"
#include <vector>
#include <core/read/readFile/read_file.h>


using core::read::ReadFile;

module::config::path::InstallPath::InstallPath() {
    
}

module::config::path::InstallPath::~InstallPath() {
    
}

std::string module::config::path::InstallPath::GetInstallPath() {
    std::string target = "";
    ReadFile *readFile = new ReadFile();
    readFile->SetPath("/etc/profile")
    std::vector<std::string> file_info_list = ReadFile->SetInfo();
    
}

bool module::config::path::InstallPath::SoftSec() {
    
}
