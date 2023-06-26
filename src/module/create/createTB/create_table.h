#ifndef MODULE_CREATE_CREATETB_CREATE_TABLE_H
#define MODULE_CREATE_CREATETB_CREATE_TABLE_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "module/show/table/show_table.h"
#include "module/show/database/show_database.h"
#include "module/config/path/data_path/data_path.h"
#include "core/create/createFile/create_file.h"


namespace module {
namespace create {

using module::show::table::ShowTable;
using module::show::database::ShowDatabase;
using module::config::path::DataPath;
using core::create::CreateFile;

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