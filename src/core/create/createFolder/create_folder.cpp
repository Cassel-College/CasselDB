#include "create_folder.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

using core::create::CreateFolderStatus;

core::create::CreateFolder::CreateFolder() {
    std::cout << "CreateFolder" << std::endl;
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

void core::create::CreateFolder::SetFolderName(const std::string& folderName) {
    if (folderName.length() < 200 && folderName.length() > 0) {
        this->folderName = folderName;
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


void core::create::CreateFolder::DoCreateFolder() {
    int key = 0;
    std::string newFolderPath;
    // check folder name
    std::string::size_type index = this->folderName.find("/");
    if (index == this->folderName.npos) {
        key = 0;
        // check folder path right.
    } else {
        key = 1;
        this->status == CreateFolderStatus::FOLDER_NAME_ERROR;
        // check folder name error, has error char in name.
    }

    // check folder path
    if (key == 0) {
        bool checkFolderPathKey = CreateFolder::HasFolder(this->path);
        if (!checkFolderPathKey) {
            this->status = CreateFolderStatus::FOLDER_PATH_NOT_EXITS;
            key = 1;
        }
    }

    // check folder exist
    if (key == 0) {
        newFolderPath = this->path + "/" + this->folderName;
        bool checkNewFoldrpathKey = CreateFolder::HasFolder(newFolderPath);
        if (!checkNewFoldrpathKey) {
            this->status = CreateFolderStatus::FOLDER_EXITS;
            key = 1;
        }
    }

    // create folder
    if (key == 0) {
        //create folder
        bool key = CreateFolder::CreateFolderCore(newFolderPath);
        // Setting create status
        if (key == true) {
            this->status = CreateFolderStatus::CREATE_SUCCESS;
        } else {
            this->status = CreateFolderStatus::CREATE_ERROR;
        }
    }
}

bool core::create::CreateFolder::HasFolder(const std::string& path) {
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

bool core::create::CreateFolder::CreateFolderCore(const std::string& path) {
    bool key = false;
    if ((path.length() > 2048) || (path.length() == 0)) {
        return key;
    }
    // Liunx create folder
    int returnKey = mkdir(path.c_str(), S_IRWXU);

    if (returnKey == 0) {
        key = true;
    } else {
        key = false;
    }
    return key;
}

