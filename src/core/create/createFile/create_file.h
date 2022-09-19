#ifndef CORE_CREATE_CREATE_FILE_H
#define CORE_CREATE_CREATE_FILE_H

#include <string>

/**
 * @brief core namespace
 * 
 * @version 1.0
 * @author liupeng (liupeng.0@outlook.com)
 * @date 2022-09-18
 * @copyright Copyright (c) 2022
 */
namespace core {
/**
 * @brief create namespace
 * 
 * @version 1.0
 * @author liupeng (liupeng.0@outlook.com)
 * @date 2022-09-18
 * @copyright Copyright (c) 2022
 */
namespace create {

enum class CreateFileStatus {
    INIT,
    FILE_NAME_ERROR,  
    FILE_PATH_NOT_EXITS,
    FILE_EXITS,
    CREATE_ERROR,
    CREATE_SUCCESS
};
/**
 * @brief Create file class.
 * 
 * @version 1.0
 * @author liupeng (liupeng.0@outlook.com)
 * @date 2022-09-18
 * @copyright Copyright (c) 2022
 */
class CreateFile
{

public:
    CreateFile(/* args */);

    ~CreateFile();

    void SetPath(const std::string& path);

    std::string GetPath() const;

    void SetFileName(const std::string& fileName);

    std::string GetFileName() const;

    void SetStatus(const CreateFileStatus& status);

    CreateFileStatus GetStatus() const;

    void DoCreateFile();
    
    static bool HasFile(const std::string& path);

    static bool CreateFileCore(const std::string& path);
    
    static bool CheckFileName(const std::string& fileName);

    static bool CheckFilePathExisted(const std::string& filePath);


private:
    /// @brief file's folder path.
    std::string path;

    /// @brief file name.
    std::string fileName;

    /// @brief Create file status.
    CreateFileStatus status;


};


}; // namespace create
}; // namespace core

#endif