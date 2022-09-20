#ifndef CORE_CREATE_CREATE_FOLDER_H
#define CORE_CREATE_CREATE_FOLDER_H
#ifndef __FILENAME__
#define __FILENAME__ (strrchr("/" __FILE__, '/') + 1)
#endif

#include <iostream>
#include <string>

namespace core {
namespace create {

enum class CreateFolderStatus {
    INIT,
    FOLDER_NAME_ERROR,  
    FOLDER_PATH_NOT_EXITS,
    FOLDER_EXITS,
    CREATE_ERROR,
    CREATE_SUCCESS
};

class CreateFolder {

public:
    
    CreateFolder();
    
    ~CreateFolder();

    void SetPath(const std::string& path);

    std::string GetPath() const;

    void SetFolderName(const std::string& folderName);

    std::string GetFolderName() const;

    void SetStatus(CreateFolderStatus status);

    CreateFolderStatus GetStatus() const;

    void DoCreateFolder();
    
    static bool CheckHasFolder(const std::string& path);

    static bool CreateFolderCore(const std::string& path);

private:
    std::string path;
    std::string folderName;
    CreateFolderStatus status;
};

}; // namespace Create
}; // namespace Core

#endif