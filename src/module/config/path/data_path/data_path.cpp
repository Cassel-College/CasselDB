#include "data_path.h"

module::config::path::DataPath::DataPath() {
    
}

module::config::path::DataPath::~DataPath() {
    
}

std::string module::config::path::DataPath::GetDataPath() {

    std::string target = "";
    std::string target_config_name = "data_path";
    std::shared_ptr<CasselConfig> cassel_config_ptr = CasselConfig::GetCasselConfigPtr();
    if (cassel_config_ptr == nullptr) {
        return target;
    } else {
        target = cassel_config_ptr->GetConfigByName(target_config_name);
    }
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
