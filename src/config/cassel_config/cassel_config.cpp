#include "cassel_config.h"

namespace config {
namespace cassel_config {

CasselConfig::CasselConfig() {
    this->config_file_path = "/config/configuration.conf";
    this->ReloadConfig();
}

bool CasselConfig::ReloadConfig() {
    this->LaodConfig(this->GetConfigPath());
    return true;
}

std::string CasselConfig::GetCasselDBExecPath() {
    char szBuf[128];
    memset(szBuf, 0x00, sizeof(szBuf));
    getcwd(szBuf, sizeof(szBuf)-1);
    std::string path(szBuf);
    return path;
}

std::string CasselConfig::GetConfigPath() {

    std::shared_ptr<log4cpp::log::Log> logMS_ptr = Log::GetLogPtr();
    logMS_ptr->add(LogModule("Begin get config path.", Level("DEBUG"), __FILE__, __LINE__, "config"));

    std::string folder_path = GetCasselDBExecPath();
    std::string path = folder_path + this->config_file_path;
    if (path.size() == config_file_path.size()) {
        path = "";
    }
    logMS_ptr->add(LogModule("Get config path over.", Level("DEBUG"), __FILE__, __LINE__, "config"));
    return path;
}

std::vector<std::string> CasselConfig::ReadConfig(const std::string &config_path) {

    std::shared_ptr<log4cpp::log::Log> logMS_ptr = Log::GetLogPtr();
    logMS_ptr->add(LogModule("Begin read cassel DB config.", Level("DEBUG"), __FILE__, __LINE__, "config"));

    std::shared_ptr<ReadFile> readFile = std::make_shared<ReadFile>();
    readFile->SetPath(config_path);
    readFile->SetInfo();

    std::vector<std::string> configration_info = readFile->GetInfo();

    logMS_ptr->add(LogModule("Read cassel DB config over.", Level("DEBUG"), __FILE__, __LINE__, "config"));
    return configration_info;
}

std::string CasselConfig::InterceptSpecialCharacters(const std::string &info) {

    std::string result;
    auto pos = info.find('#');
    if (pos != std::string::npos) {
        result = info.substr(0, pos);
    } else {
        result = info;
    }
    return result;
}

std::vector<std::string> CasselConfig::FilterComments(const std::vector<std::string>& input) {
    std::vector<std::string> result;
    for (const auto& str : input) {
        std::string temp = this->InterceptSpecialCharacters(str);
        if (temp != "") {
            result.push_back(temp);
        }
    }
    return result;
}

// 去除字符串中的空格
std::string CasselConfig::RemoveSpaces(const std::string& str) {
    std::string result;
    result.reserve(str.length()); // 提前分配足够的空间

    for (char c : str) {
        if (!std::isspace(c)) {
            result.push_back(c);
        }
    }

    return result;
}

// 处理字符串
bool CasselConfig::SplitConfig(const std::string& str, std::pair<std::string, std::string> &config_item) {
    // 去除空格
    std::string trimmedStr = this->RemoveSpaces(str);
    bool split_status = false;
    // 查找等号的位置
    std::size_t equalPos = trimmedStr.find('=');
    if (equalPos != std::string::npos) {
        // 提取变量名和值
        std::string variableName = trimmedStr.substr(0, equalPos);
        std::string value = trimmedStr.substr(equalPos + 1);
        // 输出结果
        std::cout << "{variableName: " << variableName << ", value: " << value << "}" << std::endl;
        config_item.first = variableName;
        config_item.second = value;
        split_status = true;
    } else {
        std::cout << "无效的输入格式: " << str << std::endl;
    }
    return split_status;
}


void CasselConfig::LaodConfig(const std::string &config_path) {

    std::vector<std::string> configration_info = this->FilterComments(this->ReadConfig(config_path));
    for (auto &item : configration_info) {
        std::pair<std::string, std::string> config_item;
        if (this->SplitConfig(item, config_item)) {
            this->AddConfig(config_item);
        }
    }
}

bool CasselConfig::AddConfig(std::pair<std::string, std::string> &config_item) {
    this->config_maps.insert(config_item);
    return true;
}

std::shared_ptr<CasselConfig> CasselConfig::GetCasselConfigPtr() {
    
    if (cassel_config_ptr == nullptr) {
        std::shared_ptr<CasselConfig> temp_cassel_config_ptr(new CasselConfig());
        cassel_config_ptr.swap(temp_cassel_config_ptr);
    }
    return cassel_config_ptr;
}

}; // namespace cassel_config
}; // namespace config