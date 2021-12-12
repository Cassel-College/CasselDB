#include "read_file.h"
#include <iostream>
#include <fstream>

using core::read::ReadFileStatus;

core::read::ReadFile::ReadFile() {
    this->path = "";
    this->beginLineNum = 0;
    this->endLineNum = INT32_MAX;
    this->hasFile = false;
    this->info = {};
    this->status = ReadFileStatus::INIT;
}

core::read::ReadFile::~ReadFile() {
    this->path = "";
    this->beginLineNum = -1;
    this->endLineNum = -1;
    this->hasFile = false;
    this->info = {};
    this->status = ReadFileStatus::INIT;
}

void core::read::ReadFile::SetBeginLineNum(const int beginLineNum) {
    this->beginLineNum = beginLineNum;
}

int core::read::ReadFile::GetBeginLineNum() const {
    return this->beginLineNum;
}

void core::read::ReadFile::SetEndLineNum(const int endLineNum) {
    this->endLineNum = endLineNum;
}

int core::read::ReadFile::GetEndLineNum() const {
    return this->endLineNum;
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

bool core::read::ReadFile::SetInfo() {
    std::vector<char> bytes;
    char byte = 0;
    bool key = true;
    std::ifstream input_file(this->path);
    if (!input_file.is_open()) {
        std::cout << "Could not open the file:'"<< this->path << "'" << std::endl;
        this->status = ReadFileStatus::OPEN_FILE_ERROR;
        key = false;
    } else {
        std::string buf;
        int index = 0;
        while (getline(input_file, buf))
        {
            if (index >= this->beginLineNum && index <= this->endLineNum) {
                this->info.push_back(buf);
            }
        }
        input_file.close();
    }
    this->info = info;
    return key;
}
