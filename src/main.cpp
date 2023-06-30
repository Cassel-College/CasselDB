/**
 * @file main.cpp
 * @author liupeng (liupeng.0@outlook.com)
 * @brief 程序入口
 * @version 0.1
 * @date 2022-09-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <string>
#include <memory>
#include <sstream>

#include <log4cpp/log_module/log_module.h>
#include <log4cpp/level/level.h>
#include <log4cpp/log_cache/log_cache.h>
#include <log4cpp/style4log/style4log.h>
#include <log4cpp/io4log/io4log.h>
#include <log4cpp/filter4log/filter4log.h>
#include <log4cpp/config4log/config4log.h>
#include <log4cpp/date_time/date_time.h>
#include <log4cpp/log/log.h>

#include <config/version/version.h>
#include <config/cassel_config/cassel_config.h>
#include <core/create/createFolder/create_folder.h>
#include <core/read/readFile/read_file.h>
#include <core/tools/select_info_from_list/select_info_from_list.h>
#include <module/config/path/install_path/install_path.h>
#include <module/create/createDB/create_database.h>
#include <module/show/database/show_database.h>
#include <os/manager/cassel_manager.h>

using core::create::CreateFolder;
using core::read::ReadFile;
using core::tools::SelectInfoFromList;
using module::config::path::InstallPath;
using module::create::CreateDatabase;
using module::create::CreateDataBaseStatus;
using module::show::database::ShowDatabase;
using db_config::version::Version;
using db_config::cassel_config::CasselConfig;
using log4cpp::log_module::LogModule;
using log4cpp::level::Level;
using log4cpp::log_cache::LogCache;
using log4cpp::style4log::Style4Log;
using log4cpp::io4log::IO4Log;
using log4cpp::filter4log::Filter4Log;
using log4cpp::config4log::Config4Log;
using log4cpp::date_time::DateTime;
using log4cpp::log::Log;
using cassel::os::manager::CasselManager;
using cassel::os::manager::status::CasselStatus;
using cassel::os::manager::status::CasselManagerStatus;

using VecStrPtr = std::shared_ptr<std::vector<std::string>>;

Log* log4cpp::log::Log::logMS = nullptr;
std::shared_ptr<log4cpp::log::Log> Log::logMS_ptr = nullptr;
std::shared_ptr<CasselConfig> CasselConfig::cassel_config_ptr = nullptr;

void delSpace(std::string &buf) {
    std::istringstream iss(buf);
    std::ostringstream oss;
    std::string word;
    while (iss >> word) {
        oss << word << ' ';
    }
    buf = oss.str();
    if (!buf.empty()) {
        buf.pop_back();
    }
}

void SplitStr(std::string &s, std::shared_ptr<std::vector<std::string>> result) {
    std::istringstream iss(s);
    std::string token;
    std::cout << s << std::endl;
    while (std::getline(iss, token, ' ')) {
        result->push_back(token);
        std::cout << "token:" << token << std::endl;
    }
}

int main()
{
    Log* logMS = Log::GetLog();
    logMS->add(LogModule("Begin start cassel DB.", Level("DEBUG"), __FILE__, __LINE__, "log"));
    
    std::shared_ptr<log4cpp::log::Log> logMS_ptr = Log::GetLogPtr();
    logMS_ptr->add(LogModule("Begin start cassel DB.", Level("DEBUG"), __FILE__, __LINE__, "log"));

    std::shared_ptr<CasselConfig> cassel_config_ptr = CasselConfig::GetCasselConfigPtr();

    logMS_ptr->SetLogPath(cassel_config_ptr->GetConfigByName("logs_path"));
    logMS->SetLogPath(cassel_config_ptr->GetConfigByName("logs_path"));

    cassel::os::manager::CasselManager manager_;
    std::string command;
    std::string license = cassel_config_ptr->GetConfigByName("license");

    std::shared_ptr<CasselStatus> status = std::make_shared<CasselStatus>();
    VecStrPtr operations = std::make_shared<std::vector<std::string>>();
    
    manager_.ParseOperation(operations);
    
    if (license == "19890604.lic") {
        while (true) {
            operations->clear();
            std::string target1 = "(";
            std::string target2 = ")";
            std::cout << "input command " << target1 << manager_.GetCasselStatusStr() << target2 << " >>>";
            command = "";
            std::getline(std::cin, command);

            delSpace(command);
            SplitStr(command, operations);

            manager_.ParseOperation(operations);

            if (manager_.GetLevelStatus() == CasselManagerStatus::QUIT) {
                std::cout << "over ..." << std::endl;
                break;
            } else {
                std::cout << "input command: " << manager_.GetCasselStatusStr() << std::endl;
            }
        }
    } else {
        std::cout << "license error." << std::endl;
    }
    
    logMS_ptr->send_log();
    delete logMS;
    return 0;
}

// | datetime | level | module | file | line | log infos |
// | --- | --- | --- | --- | --- | --- |
