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

#include <config/version/version.h>
#include <config/cassel_config/cassel_config.h>
#include <core/create/createFolder/create_folder.h>
#include <core/read/readFile/read_file.h>
#include <core/tools/select_info_from_list/select_info_from_list.h>
#include <module/config/path/install_path/install_path.h>
#include <module/create/createDB/create_database.h>
#include <module/show/database/show_database.h>
#include <log4cpp/log_module/log_module.h>
#include <log4cpp/level/level.h>
#include <log4cpp/log_cache/log_cache.h>
#include <log4cpp/style4log/style4log.h>
#include <log4cpp/io4log/io4log.h>
#include <log4cpp/filter4log/filter4log.h>
#include <log4cpp/config4log/config4log.h>
#include <log4cpp/date_time/date_time.h>
#include <log4cpp/log/log.h>
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

    CreateFolder *createFolder = new CreateFolder();
    createFolder->SetPath(cassel_config_ptr->GetConfigByName("data_path"));
    createFolder->SetFolderName("Palt");
    createFolder->DoCreateFolder();

    logMS_ptr->SetLogPath(cassel_config_ptr->GetConfigByName("logs_path"));
    logMS->SetLogPath(cassel_config_ptr->GetConfigByName("logs_path"));
    std::cout << "Holle World!" << std::endl;
    ReadFile *readFile = new ReadFile();
    readFile->SetPath("/etc/profile");
    readFile->SetInfo();
    std::cout << "Holle World!" << std::endl;
    std::vector<std::string> paly = readFile->GetInfo();

    paly = SelectInfoFromList::SelectInfo(paly, "CASSELDB_INSTALL_PATH", true);
    std::cout << "Holle World!" << std::endl;
    for (auto item : paly) {
        std::cout << item << std::endl;
    }

    InstallPath *installPath = new InstallPath();
    std::cout << "Holle World!-" << std::endl;
    std::string install_path = installPath->GetInstallPath();
    std::cout << "Holle World!-" << std::endl;
    std::cout << install_path << std::endl;

    Version *version = new Version();
    std::cout << version->get_version() << std::endl;
    logMS->send_log();

    std::cout << "Test read file." << std::endl;
    std::shared_ptr<core::read::ReadFile> readfile_ptr = std::make_shared<core::read::ReadFile>();
    readfile_ptr->SetPath("/home/Code/github/CasselDB/README.md");
    readfile_ptr->SetInfo();
    auto infos = readfile_ptr->GetInfo();
    core::read::ShowInfo(infos);

    cassel::os::manager::CasselManager manager_;
    std::shared_ptr<CasselStatus> status = std::make_shared<CasselStatus>();
    std::shared_ptr<std::vector<std::string>> operations = std::make_shared<std::vector<std::string>>();
    manager_.ParseOperation(operations);
    std::string command;
    std::string license = cassel_config_ptr->GetConfigByName("license");
    while (license == "19890604-") {
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
    logMS_ptr->send_log();
    delete logMS;
    return 0;
}