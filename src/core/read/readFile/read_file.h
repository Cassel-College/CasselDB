#ifndef CORE_READ_READ_FILR_H
#define CORE_READ_READ_FILR_H

#include <string> 
#include <vector>

namespace core {
namespace read {

enum class ReadFileStatus {
    INIT,
    NO_FILE,
    READ_FILE_SUCCESS,
    OPEN_FILE_ERROR,
};
class ReadFile {

public:
    ReadFile();

    ~ReadFile();

    void SetBeginLineNum(const int beginLineNum);

    int GetBeginLineNum() const;

    void SetEndLineNum(const int endLineNum);

    int GetEndLineNum() const;

    void SetPath(const std::string& path);

    std::string GetPath() const;

    void SetHasFile(const bool hasFile);

    bool GetHasFile() const;

    std::vector<std::string> GetInfo() const;

    bool SetInfo();
    
private:

    std::string path;

    int beginLineNum;

    int endLineNum;

    bool hasFile;

    std::vector<std::string> info;

    ReadFileStatus status;
};

}; // namespace read
}; // namespace core

#endif