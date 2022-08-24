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


int main()
{
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
    return 0;
}