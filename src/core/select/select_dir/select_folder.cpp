#include "select_folder.h"

#include <dirent.h>
#include <math.h>
#include <iostream>

core::select::SelectFolder::SelectFolder() {
    
}

core::select::SelectFolder::~SelectFolder() {

}

std::vector<std::string> core::select::SelectFolder::GetFolderListByPath(const std::string &path = "") {
    std::vector<std::string> dbNameList = {};
    if (fabs(0 - path.compare("")) < 1e-9) {
        return dbNameList;
    }
    struct dirent *dirp;
    DIR* dir = opendir(path.c_str());
    while ((dirp = readdir(dir)) != nullptr) {
        if (dirp->d_type == DT_REG) {
            continue;
        } else if (dirp->d_type == DT_DIR) {
            if (0 == std::string(dirp->d_name).compare(".")) {
                continue;
            }
            if (0 == std::string(dirp->d_name).compare("..")) {
                continue;
            }
            dbNameList.push_back(dirp->d_name);
        }
    }
    closedir(dir);
    return dbNameList;
}

std::vector<std::string> core::select::SelectFolder::GetFileListByPath(const std::string &path = "") {
    std::vector<std::string> dbNameList = {};
    if (fabs(0 - path.compare("")) < 1e-9) {
        return dbNameList;
    }
    struct dirent *dirp;
    DIR* dir = opendir(path.c_str());
    while ((dirp = readdir(dir)) != nullptr) {
        if (dirp->d_type == DT_REG) {
            dbNameList.push_back(dirp->d_name);
        } else if (dirp->d_type == DT_DIR) {
            continue;
        }
    }
    closedir(dir);
    return dbNameList;
}
