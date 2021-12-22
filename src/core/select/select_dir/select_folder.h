#ifndef CORE_SELECT_SELECT_DIR_H
#define CORE_SELECT_SELECT_DIR_H

#include <string>
#include <vector>

namespace core {
namespace select {

class SelectFolder {

public:

    SelectFolder();

    ~SelectFolder();

    static std::vector<std::string> GetFolderListByPath(const std::string &path);

    static std::vector<std::string> GetFileListByPath(const std::string &path);

private:

    std::vector<std::string> folderList;

    std::vector<std::string> fileList;

};

}; // namespace select
}; // namespace core

#endif