#include <iostream>
#include <string>

#include <core/create/createFolder/create_folder.h>
#include <core/read/readFile/read_file.h>

using core::create::CreateFolder;
using core::read::ReadFile;

int main()
{
    CreateFolder *createFolder = new CreateFolder();
    std::cout << "Holle World!" << std::endl;
    ReadFile *readFile = new ReadFile();
    readFile->SetPath("/etc/profile");
    readFile->SetInfo();
    std::vector<std::string> paly = readFile->GetInfo();
    for (auto info : paly) {
        std::cout << info << std::endl;
    }
    return 0;
}