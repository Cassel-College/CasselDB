#ifndef CORE_CREATE_CREATE_FOLDER_H
#define CORE_CREATE_CREATE_FOLDER_H

#include <iostream>
#include <string>

namespace core {
namespace create {

class CreateFolder {

public:
    
    CreateFolder();
    
    ~CreateFolder();

private:
    std::string path;
    std::string folderName;
    int status;
};

}; // namespace Create
}; // namespace Core

#endif