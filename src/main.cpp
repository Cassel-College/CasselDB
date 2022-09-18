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

#include <config/version/version.h>
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

using core::create::CreateFolder;
using core::read::ReadFile;
using core::tools::SelectInfoFromList;
using module::config::path::InstallPath;
using module::create::CreateDatabase;
using module::create::CreateDataBaseStatus;
using module::show::database::ShowDatabase;
using config::version::Version;
using log4cpp::log_module::LogModule;
using log4cpp::level::Level;
using log4cpp::log_cache::LogCache;
using log4cpp::style4log::Style4Log;
using log4cpp::io4log::IO4Log;
using log4cpp::filter4log::Filter4Log;
using log4cpp::config4log::Config4Log;
using log4cpp::date_time::DateTime;
using log4cpp::log::Log;


Log* log4cpp::log::Log::logMS = nullptr;


/**
 * @brief test case by Dev to test log module.
 * 
 * @version 1.0
 * @author liupeng (liupeng.0@outlook.com)
 * @date 2022-09-18
 * @copyright Copyright (c) 2022
 */
void dev_test_log()
{
    Log* logMS = Log::GetLog();
    LogModule *log = new LogModule();
    log->set_log_info("log information.");
    log->show_log();


    if (Level::compare(Level("DEBUG"), Level("INFO"))) {
        log->set_log_info("print");
    } else {
        log->set_log_info("not print");
    }
    log->show_log();
    delete log;

    LogCache *log_cache = new LogCache();
    log_cache->append(LogModule(std::string("111"), Level(1)));
    log_cache->append(LogModule(std::string("222"), Level(2)));
    log_cache->append(LogModule(std::string("113"), Level(0)));
    log_cache->append(LogModule(std::string("224"), Level(2)));
    log_cache->append(LogModule(std::string("115"), Level(2)));
    log_cache->append(LogModule(std::string("226"), Level("DEBUG")));
    log_cache->append(LogModule("Start docker", Level("INFO"), __FILE__, __LINE__));
    log_cache->append(LogModule("Enter docker", Level("DEBUG"), __FILE__, __LINE__, "log"));
    log_cache->append(LogModule("Start docker", Level("ERROR"), __FILE__, __LINE__));
    log_cache->append(LogModule("Enter docker", Level("DEBUG"), __FILE__, __LINE__, "log"));

    std::cout << "------------------------" << std::endl;
    log_cache->show();
    log_cache->filtter(Level(1));
    std::cout << "------------------------" << std::endl;
    log_cache->show();
    
    delete log_cache;

    LogModule log_a = LogModule();
    Style4Log *style = new Style4Log(log_a);
    std::cout << style->get_log_information() << std::endl;

    IO4Log *io = new IO4Log("ccc");
    io->wirte("opop");

    Config4Log *config = new Config4Log();
    std::cout << config->getFilterLevel() << std::endl;

    DateTime dt = DateTime();
    dt.show_now();

    logMS->add(LogModule("Stop Cassel DB.", Level("DEBUG"), __FILE__, __LINE__, "log"));
    logMS->send_log();

    delete logMS;
}


int main()
{
    Log* logMS = Log::GetLog();
    logMS->add(LogModule("Begin start cassel DB.", Level("DEBUG"), __FILE__, __LINE__, "log"));
    
    CreateFolder *createFolder = new CreateFolder();
    createFolder->SetPath("/opt/CasselDB/data");
    createFolder->SetFolderName("Palt");
    createFolder->DoCreateFolder();
    std::cout << "Holle World!" << std::endl;
    ReadFile *readFile = new ReadFile();
    readFile->SetPath("/etc/profile");
    readFile->SetInfo();
    std::cout << "Holle World!" << std::endl;
    std::vector<std::string> paly = readFile->GetInfo();

    paly = SelectInfoFromList::SelectInfo(paly, "CASSELDB_INS·TALL_PATH", true);
    std::cout << "Holle World!" << std::endl;
    for (auto item : paly) {
        std::cout << item << std::endl;
    }

    InstallPath *installPath = new InstallPath();
    std::cout << "Holle World!-" << std::endl;
    std::string install_path = installPath->GetInstallPath();
    std::cout << "Holle World!-" << std::endl;
    std::cout << install_path << std::endl;

    // std::cout << "-----------------Begin Test Create Databases-----------------" << std::endl;
    // CreateDatabase *createDatabase = new CreateDatabase();
    // std::cout << "Begin..." << std::endl;
    // createDatabase->SetDatabasesName("testDB");
    // std::cout << "Test dataBase name: testDB" << std::endl;
    // std::cout << createDatabase->GetBashPath() << std::endl;
    // std::cout << createDatabase->GetDatabaseName() << std::endl;
    // bool key = createDatabase->Create();
    // std::cout << "Create..." << std::endl;
    // if (key) {
    //     std::cout << "Create Success!" << std::endl;
    // } else {
    //     std::cout << "Create Error!" << std::endl;
    // }
    // std::cout << "-----------------End   Test Create Databases-----------------" << std::endl;

    // ShowDatabase *showDatabase = new ShowDatabase();
    // showDatabase->SetDBNameList();
    // for (auto item : showDatabase->GetDBNamelist()) {
    //     std::cout << " -- :" << item  << std::endl;
    // }

    Version *version = new Version();
    std::cout << version->get_version() << std::endl;

    dev_test_log();
    return 0;
}