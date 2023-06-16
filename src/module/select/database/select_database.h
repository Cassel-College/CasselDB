#ifndef MODULE_SELECT_SELECT_DATABASE_H
#define MODULE_SELECT_SELECT_DATABASE_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <memory>

#include <core/select/select_dir/select_folder.h>


namespace module {
namespace select {
namespace select_databases {
    
class SelectDataBase {
    
public:

    SelectDataBase();

    ~SelectDataBase();

    void SetBashPath(const std::string& bashPath);

    std::string GetBashPath() const;

    bool AddDatabase(const std::string& database);

    std::shared_ptr<std::vector<std::string>> GetDatabaseNames();

private:

    std::shared_ptr<std::vector<std::string>> databases_infos_ptr;
    std::string bashPath;

};
}; // namespace select_databases
}; // namespace select
}; // namespace module

#endif // MODULE_SELECT_SELECT_DATABASE_H