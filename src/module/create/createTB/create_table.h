#ifndef MODULE_CREATE_CREATETB_CREATE_TABLE_H
#define MODULE_CREATE_CREATETB_CREATE_TABLE_H

#include <string>
namespace module {
namespace create {

enum class CreateTableStatus {
    INIT,
    NO_DATABASE,
    HAS_SAME_TABLE,
    ERROR_TABLE_NAME,
    SUCCESS,
};

class CreateTable {

public:
    CreateTable();
    
    ~CreateTable();

    void SetTableName(const std::string& tableName);

    std::string GetTableName() const;

    void SetDatabaseName(const std::string& databaseName);

    std::string GetDatabaseName() const;

    void SetStatus(CreateTableStatus status);

    CreateTableStatus Getstatus();

    bool CheckEnvironment();

    // select 
    bool HasSameTableInDatabase() const;

    bool HasDatabase() const;

    void CraeteTable();

    void CreateTableCore();

private:

    std::string tableName;

    std::string databaseName;

    CreateTableStatus status;

};

}; // namespace module
}; // namespace create

#endif