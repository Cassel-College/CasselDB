#ifndef CORE_READ_READ_FILR_H
#define CORE_READ_READ_FILR_H

#include <string> 
#include <vector>

namespace core {
namespace read {

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

    void SetInfo(const std::vector<std::string>& info);
    
private:

    std::string path;

    int beginLineNum;

    int endLIneNum;

    bool hasFile;

    std::vector<std::string> info;
};

}; // namespace read
}; // namespace core

#endif