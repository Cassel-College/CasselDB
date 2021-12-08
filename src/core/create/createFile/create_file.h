#ifndef CORE_CREATE_CREATE_FILE_H
#define CORE_CREATE_CREATE_FILE_H

#include <string>

namespace core {
namespace create {

enum class CreateFileStatus {
    INIT,
    FILE_NAME_ERROR,  
    FILE_PATH_NOT_EXITS,
    FILE_EXITS,
    CREATE_ERROR,
    CREATE_SUCCESS
};
class CreateFile
{

public:
    CreateFile(/* args */);

    ~CreateFile();

    void SetPath(const std::string& path);

    std::string GetPath() const;

    void SetFileName(const std::string& fileName);

    std::string GetFolderName() const;

    void SetStatus(const CreateFileStatus& status);

    CreateFileStatus GetStatus() const;

private:
    /* data */
    std::string path;

    std::string fileName;

    CreateFileStatus status;


};


}; // namespace create
}; // namespace core

#endif