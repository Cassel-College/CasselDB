#ifndef MODULE_SHOW_TABLE_SHOW_TABLE_H
#define MODULE_SHOW_TABLE_SHOW_TABLE_H

#include <string>
#include <vector>


namespace module {
namespace show {
class ShowTable {

public:

    ShowTable();

    ~ShowTable();

    std::string GetDataBaseName() const;

    void SetDatabaseName(const std::string &databasesName);

    std::vector<std::string> GetTableList() const;

private:
    std::string databaseName;
    std::vector<std::string> tableList;

}; // class show table
}; // namespace show
}; // namespace module

#endif