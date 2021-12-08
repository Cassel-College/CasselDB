#include "read_file.h"

core::read::ReadFile::ReadFile() {
    
}

core::read::ReadFile::~ReadFile() {
    
}

void core::read::ReadFile::SetBeginLineNum(const int beginLineNum) {
    this->beginLineNum = beginLineNum;
}

int core::read::ReadFile::GetBeginLineNum() const {
    return this->beginLineNum;
}

void core::read::ReadFile::SetEndLineNum(const int endLineNum) {
    this->endLIneNum = endLIneNum;
}

int core::read::ReadFile::GetEndLineNum() const {
    return this->endLIneNum;
}

void core::read::ReadFile::SetPath(const std::string& path) {
    this->path = path;
}

std::string core::read::ReadFile::GetPath() const {
    return this->path;
}

void core::read::ReadFile::SetHasFile(const bool hasFile) {
    this->hasFile = hasFile;
}

bool core::read::ReadFile::GetHasFile() const {
    return this->hasFile;
}

std::vector<std::string> core::read::ReadFile::GetInfo() const {
    return this->info;
}

void core::read::ReadFile::SetInfo(const std::vector<std::string>& info) {
    this->info = info;
}
