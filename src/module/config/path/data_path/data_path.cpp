#include "data_path.h"

module::config::path::DataPath::DataPath() {
    
}

module::config::path::DataPath::~DataPath() {
    
}

std::string module::config::path::DataPath::GetDataPath() {

    std::string target = "";
    std::string target_config_name = "data_path";
    std::cout << "database data path:" << target << "." << std::endl;
    std::shared_ptr<CasselConfig> cassel_config_ptr = CasselConfig::GetCasselConfigPtr();
    std::cout << "database data path:" << target << "." << std::endl;
    if (cassel_config_ptr == nullptr) {
        target = "";
        std::cout << "database data path111:" << target << "." << std::endl;
    } else {
        std::cout << "database data path222:" << target << "." << std::endl;
        target = cassel_config_ptr->GetConfigByName(target_config_name);
        std::cout << "database data path222:" << target << "." << std::endl;
    }
    std::cout << "database data path:" << target << "." << std::endl;
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
