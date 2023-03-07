#include "create_folder.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

#include <log4cpp/log/log.h>
#include <log4cpp/level/level.h>
#include <log4cpp/log_module/log_module.h>

using log4cpp::log::Log;
using log4cpp::level::Level;
using log4cpp::log_module::LogModule;

using core::create::CreateFolderStatus;

core::create::CreateFolder::CreateFolder() {
    Log* logMS = Log::GetLog();
    logMS->add(LogModule("Create folder", Level("INFO"), __FILENAME__, __LINE__, "core"));
    this->path = "";
    this->folderName = "";
    this->status = CreateFolderStatus::INIT;
}

core::create::CreateFolder::~CreateFolder() {
    this->path = "";
    this->folderName = "";
    this->status = CreateFolderStatus::INIT;
}

void core::create::CreateFolder::SetPath(const std::string& path) {
    if (path.length() < 1000 && path.length() > 0) {
        this->path = path;
    }
}

std::string core::create::CreateFolder::GetPath() const {
    return this->path;   
}

void core::create::CreateFolder::SetFolderName(const std::string& folderName) 
{
    Log* logMS = Log::GetLog();
    if (folderName.length() < 200 && folderName.length() > 0) {
        this->folderName = folderName;
        logMS->add(LogModule("Set folder name over", Level("INFO"), __FILENAME__, __LINE__, "core"));
    } else {
        logMS->add(LogModule("folder name length was so long, big then 200.", Level("ERROR"), __FILENAME__, __LINE__, "core"));
    }
}

std::string core::create::CreateFolder::GetFolderName() const {
    return this->folderName;
}

void core::create::CreateFolder::SetStatus(CreateFolderStatus status) {
    this->status = status;
}

CreateFolderStatus core::create::CreateFolder::GetStatus() const {
    return this->status;
}

void print_log(const std::string& log) {
    std::cout << log << std::endl;
}

void core::create::CreateFolder::DoCreateFolder() 
{
    Log* logMS = Log::GetLog();
    int key = 0;
    std::string newFolderPath;
    logMS->add(LogModule("Begin check folder name.", Level("INFO"), __FILENAME__, __LINE__, "core"));
    std::string::size_type index = this->folderName.find("/");
    if (index == this->folderName.npos) {
        key = 0;
        logMS->add(LogModule("Check folder path right.", Level("INFO"), __FILENAME__, __LINE__, "core"));
    } else {
        key = 1;
        this->status == CreateFolderStatus::FOLDER_NAME_ERROR;
        logMS->add(LogModule("Check folder name error, has error char in name.",
                   Level("ERROR"), __FILENAME__, __LINE__, "core"));
    }
    print_log("key:" + std::to_string(key));
    print_log("check folder name");
    // check folder path
    if (key == 0) {
        bool checkFolderPathKey = CreateFolder::CheckHasFolder(this->path);
        if (!checkFolderPathKey) {
            this->status = CreateFolderStatus::FOLDER_PATH_NOT_EXITS;
            key = 1;
        }
    }
    print_log("key:" + std::to_string(key));
    print_log("check folder path");
    // check folder exist
    if (key == 0) {
        newFolderPath = this->path + "/" + this->folderName;
        bool checkNewFoldrpathKey = CreateFolder::CheckHasFolder(newFolderPath);
        if (checkNewFoldrpathKey) {
            this->status = CreateFolderStatus::FOLDER_EXITS;
            key = 1;
        }
    }
    print_log("key:" + std::to_string(key));
    print_log("create folder");
    // create folder
    if (key == 0) {
        //create folder
        bool createKey = CreateFolder::CreateFolderCore(newFolderPath);
        print_log("path: " + newFolderPath);
        // Setting create status
        if (createKey == true) {
            this->status = CreateFolderStatus::CREATE_SUCCESS;
            print_log("create: Y");
        } else {
            this->status = CreateFolderStatus::CREATE_ERROR;
            print_log("create: N");
        }
    }
}

bool core::create::CreateFolder::CheckHasFolder(const std::string& path) {
    bool key = false;
    if (path.length() > 2048) {
        return key;
    }
    // Liunx create folder
    int returnKey = access(path.c_str(), F_OK);
    print_log(std::to_string(returnKey));
    if (returnKey == 0) {
        key = true;
        print_log("exist!");
    } else {
        key = false;
        print_log("not exist!");
    }
    return key;
}

bool core::create::CreateFolder::CreateFolderCore(const std::string& path) {
    bool key = false;
    if ((path.length() > 2048) || (path.length() == 0)) {
        return key;
    }
    // Liunx create folder
    int returnKey = ::mkdir(path.c_str(), S_IRWXU);
    print_log("---------------->>>> create folder...........");

    if (returnKey == 0) {
        key = true;
    } else {
        key = false;
    }
    return key;
}

