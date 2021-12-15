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

    GetAllDatabases();

private:

    std::vector<std::string> databases;

};

}; // namespace database
}; // namespace show
}; // namespace module


#endif