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
#include "create_file.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

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
void core::create::CreateFile::DoCreateFile() {
    int key = 0;
    std::string newFolderPath;
    // check file name
    std::string::size_type index = this->fileName.find("/");
    if (index == this->fileName.npos) {
        key = 0;
        // check folder path right.
    } else {
        key = 1;
        this->status == CreateFileStatus::FILE_NAME_ERROR;
        // check folder name error, has error char in name.
    }

    // check file path
    if (key == 0) {
        bool checkFolderPathKey = CreateFile::HasFile(this->path);
        if (!checkFolderPathKey) {
            this->status = CreateFileStatus::FILE_PATH_NOT_EXITS;
            key = 1;
        }
    }

    // create file
    if (key == 0) {
        //create file
        bool key = CreateFile::CreateFileCore(this->path);
        // Setting create status
        if (key == true) {
            this->status = CreateFileStatus::CREATE_SUCCESS;
        } else {
            this->status = CreateFileStatus::CREATE_ERROR;
        }
    }
}


/**
 * @brief Check the file path has existes file. If the file was existes, return true, else return false.
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
bool core::create::CreateFile::HasFile(const std::string& path) {
    bool key = false;
    if (path.length() > 2048) {
        return key;
    }
    // Liunx create folder
    int returnKey = access(path.c_str(), F_OK);

    if (returnKey == 0) {
        key = true;
    } else {
        key = false;
    }
    return key;
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
    bool key = false;
    if ((path.length() > 2048) || (path.length() == 0)) {
        return key;
    }
    // check file exist
    key = CreateFile::HasFile(path);
    if (CreateFile::HasFile(path)) {
        key = false;
    } else {
        FILE *file = fopen(path.c_str(), "a+");
        if (file == nullptr) {
            key = false;
        } else {
            key = true;
        }
    }
    return key;
}

}; //namespace create 
}; //namespace core