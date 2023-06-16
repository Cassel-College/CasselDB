#include "install_path.h"

module::config::path::InstallPath::InstallPath() {
    
}

module::config::path::InstallPath::~InstallPath() {
    
}

std::string module::config::path::InstallPath::GetInstallPath() {
    std::string target = "";
    std::string target_config_name = "install_path";
    std::shared_ptr<CasselConfig> cassel_config_ptr = CasselConfig::GetCasselConfigPtr();
    if (cassel_config_ptr == nullptr) {
        return target;
    } else {
        target = cassel_config_ptr->GetConfigByName(target_config_name);
    }
    return target;
}

bool module::config::path::InstallPath::SoftSec() {
    std::string installPath = InstallPath::GetInstallPath();
    bool key = false;
    if (installPath.length() > 2048 || installPath.length() == 0) {
        return key;
    }
    // Liunx create folder
    int returnKey = access(installPath.c_str(), F_OK);

    if (returnKey == 0) {
        key = true;
    } else {
        key = false;
    }
    return key;
}