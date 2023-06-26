/**
 * @file create_file.cpp
 * @author liupeng (liupeng.0@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

#include "create_file.h"

#include <log4cpp/log/log.h>
#include <log4cpp/level/level.h>
#include <log4cpp/log_module/log_module.h>

/**
 * @brief core namespace
 * 
 * @version 0.1
 * @author liupeng (liupeng.0@outlook.com)
 * @date 2022-09-16
 * @copyright Copyright (c) 2022
 */
namespace core {
/**
 * @brief create namespace
 * 
 * @version 0.1
 * @author liupeng (liupeng.0@outlook.com)
 * @date 2022-09-16
 * @copyright Copyright (c) 2022
 */
namespace create {

using log4cpp::log::Log;
using log4cpp::level::Level;
using log4cpp::log_module::LogModule;

/**
 * @brief Create file create function.
 * 
 * @version 0.1
 * @author liupeng (liupeng.0@outlook.com)
 * @date 2022-09-16
 * @copyright Copyright (c) 2022
 */
core::create::CreateFile::CreateFile(/* args */) {
    this->fileName = "";
    this->path = "";
    this->status = core::create::CreateFileStatus::INIT;
}

/**
 * @brief Destroy the core::create::Create File::Create File object
 * 
 * @version 0.1
 * @author liupeng (liupeng.0@outlook.com)
 * @date 2022-09-16
 * @copyright Copyright (c) 2022
 */
core::create::CreateFile::~CreateFile() {
    this->fileName = "";
    this->path = "";
    this->status = core::create::CreateFileStatus::INIT;
}

/**
 * @brief Set file path in CreateFile class object.
 * 
 * @param path file path
 * @version 0.1
 * @author liupeng (liupeng.0@outlook.com)
 * @date 2022-09-16
 * @copyright Copyright (c) 2022
 */
void core::create::CreateFile::SetPath(const std::string& path) {
    this->path = path;
}

/**
 * @brief Get file path in CreateFile class object.
 * 
 * @return std::string File path.
 * @version 0.1
 * @author liupeng (liupeng.0@outlook.com)
 * @date 2022-09-16
 * @copyright Copyright (c) 2022
 * @return std::string 
 */
std::string core::create::CreateFile::GetPath() const {
    return this->path;
}

/**
 * @brief Set file name in CreateFile class object.
 * 
 * @param fileName File name.
 * @version 0.1
 * @author liupeng (liupeng.0@outlook.com)
 * @date 2022-09-16
 * @copyright Copyright (c) 2022
 */
void core::create::CreateFile::SetFileName(const std::string& fileName) {
    this->fileName = fileName;
}

/**
 * @brief Get file name in CreateFile object.
 * 
 * @return std::string File name.
 * @version 0.1
 * @author liupeng (liupeng.0@outlook.com)
 * @date 2022-09-16
 * @copyright Copyright (c) 2022
 * @return std::string 
 */
std::string core::create::CreateFile::GetFileName() const {
    return this->fileName;
}

/**
 * @brief Set create file status in CreateFile object.
 * 
 * @param status CreateFileStatus type, enum class.
 * @version 0.1
 * @author liupeng (liupeng.0@outlook.com)
 * @date 2022-09-16
 * @copyright Copyright (c) 2022
 */
void core::create::CreateFile::SetStatus(const CreateFileStatus& status) {
    this->status = status;
}

/**
 * @brief Get create file status in CreateFile object.
 * 
 * @return CreateFileStatus 
 * @version 0.1
 * @author liupeng (liupeng.0@outlook.com)
 * @date 2022-09-16
 * @copyright Copyright (c) 2022
 * @return CreateFileStatus 
 */
CreateFileStatus core::create::CreateFile::GetStatus() const {
    return this->status;
}


/**
 * @brief Do create file action.
 * 
 * @version 0.1
 * @author liupeng (liupeng.0@outlook.com)
 * @date 2022-09-16
 * @copyright Copyright (c) 2022
 */
CreateFileStatus core::create::CreateFile::DoCreateFile() {

    Log* logMS = Log::GetLog();
    if (CreateFile::CheckFileName(fileName)) {
        std::cout << "Right file name." << std::endl;
        if (CreateFile::CheckFilePathExisted(path)) {
            std::cout << "File was existed." << std::endl;
            status = CreateFileStatus::FILE_EXITS;
        } else {
            std::cout << "File not existed!" << std::endl;
            status = CreateFileStatus::FILE_PATH_NOT_EXITS;
            std::string allFilePath = path + "/" + fileName;
            logMS->add(LogModule("Begin create file:" + allFilePath, Level("INFO"), __FILENAME__, __LINE__, "core"));
            if (CreateFile::CreateFileCore(allFilePath)) {
                status = CreateFileStatus::CREATE_SUCCESS;
            } else {
                status = CreateFileStatus::CREATE_ERROR;
            }
        }
    } else {
        std::cout << "Error file name." << std::endl;
        status = CreateFileStatus::FILE_NAME_ERROR;
    }
    return status;
}


/**
 * @brief Check file name has error char, like '/'.
 * 
 * @param fileName
 * @return true 
 * @return false 
 * @version 1.0
 * @author liupeng (liupeng.0@outlook.com)
 * @date 2022-09-19
 * @copyright Copyright (c) 2022
 */
bool core::create::CreateFile::CheckFileName(const std::string& fileName) {

    Log* logMS = Log::GetLog();
    logMS->add(LogModule("Check file name", Level("INFO"), __FILENAME__, __LINE__, "core"));
    bool fileNameState = false;
    std::string::size_type index = fileName.find("/");
    if (index == fileName.npos) {
        fileNameState = true;
        logMS->add(LogModule("file name was right.", Level("INFO"), __FILENAME__, __LINE__, "core"));
    } else {
        logMS->add(LogModule("Check file name error, has error char in name.", Level("ERROR"), __FILENAME__, __LINE__, "core"));
        fileNameState = false;
    }
    return fileNameState;
}


bool core::create::CreateFile::CheckFilePathExisted(const std::string& filePath) {
    Log* logMS = Log::GetLog();
    if (filePath.length() > 2048) {
        logMS->add(LogModule("The path string length bigger than 2048.", Level("ERROR"), __FILENAME__, __LINE__, "core"));
        return false;
    }
    logMS->add(LogModule("Check Liunx has file path." + filePath, Level("INFO"), __FILENAME__, __LINE__, "core"));
    int returnKey = access(filePath.c_str(), F_OK);
    if (returnKey == 0) {
        logMS->add(LogModule("File was not existed." + filePath, Level("INFO"), __FILENAME__, __LINE__, "core"));
    } else {
        logMS->add(LogModule("File has been existed!" + filePath, Level("INFO"), __FILENAME__, __LINE__, "core"));
    }
    return returnKey != 0;
}


/**
 * @brief Create file care action.
 * 
 * @param path std::string type, file path.
 * @return true 
 * @return false 
 * @version 0.1
 * @author liupeng (liupeng.0@outlook.com)
 * @date 2022-09-16
 * @copyright Copyright (c) 2022
 * @return true 
 * @return false 
 */
bool core::create::CreateFile::CreateFileCore(const std::string& path) {

    Log* logMS = Log::GetLog();
    logMS->add(LogModule("Create File core action.", Level("INFO"), __FILENAME__, __LINE__, "core"));

    bool key = false;
    logMS->add(LogModule("Check path string length.", Level("INFO"), __FILENAME__, __LINE__, "core"));

    if ((path.length() > 2048) || (path.length() == 0)) {
        logMS->add(LogModule("File path string's length was not right.", Level("ERROR"), __FILENAME__, __LINE__, "core"));
        return key;
    }
    FILE *file = fopen(path.c_str(), "a+");
    if (file == nullptr) {
        logMS->add(LogModule("Create file failed!", Level("ERROR"), __FILENAME__, __LINE__, "core"));
    } else {
        logMS->add(LogModule("Create file success.", Level("ERROR"), __FILENAME__, __LINE__, "core"));
        key = true;
    }
    return key;
}

}; //namespace create 
}; //namespace core