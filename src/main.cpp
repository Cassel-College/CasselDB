#include <iostream>
#include <string>

#include <core/create/createFolder/create_folder.h>

using core::create::CreateFolder;

int main()
{
    CreateFolder *createFolder = new CreateFolder();
    std::cout << "Holle World!" << std::endl;
    return 0;
}