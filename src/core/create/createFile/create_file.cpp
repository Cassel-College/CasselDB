#include "create_file.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

namespace core {
namespace create {

core::create::CreateFile::CreateFile(/* args */) {
    this->fileName = "";
    this->path = "";
    this->status = core::create::CreateFileStatus::INIT;
}

core::create::CreateFile::~CreateFile() {
    this->fileName = "";
    this->path = "";
    this->status = core::create::CreateFileStatus::INIT;
}

void core::create::CreateFile::SetPath(const std::string& path) {
    this->path = path;
}

std::string core::create::CreateFile::GetPath() const {
    return this->path;
}

void core::create::CreateFile::SetFileName(const std::string& fileName) {
    this->fileName = fileName;
}

std::string core::create::CreateFile::GetFolderName() const {
    return this->fileName;
}

void core::create::CreateFile::SetStatus(const CreateFileStatus& status) {
    this->status = status;
}

CreateFileStatus core::create::CreateFile::GetStatus() const {
    return this->status;
}

}; //namespace create 
}; //namespace core


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

bool core::create::CreateFile::CreateFileCore(const std::string& path) {
    bool key = false;
    if ((path.length() > 2048) || (path.length() == 0)) {
        return key;
    }
    // check file exist
    bool key = CreateFile::HasFile(path);
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
