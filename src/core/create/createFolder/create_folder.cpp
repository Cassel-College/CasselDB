#include "create_folder.h"

core::create::CreateFolder::CreateFolder() {
    std::cout << "CreateFolder" << std::endl;
    this->path = "";
    this->folderName = "";
    this->status = 0;
}

core::create::CreateFolder::~CreateFolder() {
    this->path = "";
    this->folderName = "";
    this->status = 0;
}
