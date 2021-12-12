#ifndef MODULE_CREATE_CREATEDB_CRAETE_DATABASE_H
#define MODULE_CREATE_CREATEDB_CRAETE_DATABASE_H

#include <iostream>
#include <string>

namespace module {
namespace create {

enum class CreateDataBaseStatus {
    INIT,
    DB_EXIST,
    CREATE_SUCCESS,
    CREATE_ERROR,
};

class CreateDatabase {

public:

    CreateDatabase();

    ~CreateDatabase();

    void SetBashPath(const std::string& bashPath);

    std::string GetBashPath() const;

    void SetDatabasesName(const std::string& dataBaseName);

    std::string getDatabasename() const;
    
    void SetCreateDataBaseStatus(CreateDataBaseStatus status);

    CreateDataBaseStatus GetCreateDataBaseStatus() const;

private:

    std::string bashPath;

    std::string dataBaseName;

    CreateDataBaseStatus status;
};

}; // namespace create
}; // namespace module

#endif