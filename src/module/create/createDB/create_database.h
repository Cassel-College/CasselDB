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
    NOT_INSRTALL_CASSEL_DB,
    NO_CASSEL_DB_PATH,
    CASSEL_DB_INSTALL,
    EXIST_CASSEL_DB_PATH,
    ENVIRONMENT_OK,

};

class CreateDatabase {

public:

    CreateDatabase();

    ~CreateDatabase();

    void SetBashPath(const std::string& bashPath);

    std::string GetBashPath() const;

    void SetDatabasesName(const std::string& dataBaseName);

    std::string GetDatabaseName() const;
    
    void SetCreateDataBaseStatus();

    CreateDataBaseStatus GetCreateDataBaseStatus() const;

    bool Create();

    bool CheckDataBaseName();

    bool CheckDatabasesPath();

private:

    std::string bashPath;

    std::string dataBaseName;

    CreateDataBaseStatus status;
};

}; // namespace create
}; // namespace module

#endif