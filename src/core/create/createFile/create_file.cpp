#include "create_file.h"

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

