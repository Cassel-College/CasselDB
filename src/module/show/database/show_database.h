#ifndef MODULE_SHOW_DATABASE_SHOW_DATABASE_H
#define MODULE_SHOW_DATABASE_SHOW_DATABASE_H

#include <vector>
#include <string>

namespace module {
namespace show {
namespace database {
class ShowDatabase {

public:

    ShowDatabase();

    ~ShowDatabase();

    void SetDataPath(const std::string &path);

    std::string GetDataPath() const;

    void SetDBNameList();

    std::vector<std::string> GetDBNamelist() const;

private:

    std::string dataPath;

    std::vector<std::string> dbNameList;

};

}; // namespace database
}; // namespace show
}; // namespace module


#endif