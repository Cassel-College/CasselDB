#ifndef CASSEL_OS_MANAGER_CASSEL_STATUS_H
#define CASSEL_OS_MANAGER_CASSEL_STATUS_H
/**
 * @brief 
 * 
 * @version 0.1
 * @author liupeng (liupeng.0@outlook.com)
 * @date 2023-03-01
 * @copyright Copyright (c) 2023
 */

#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <memory>

namespace cassel {
namespace os {
namespace manager {
namespace status {

enum class CasselManagerStatus {
    DEFAULT,
    DATABASE,
    TABLE,
    CONFIG,
    QUIT
};

class CasselStatus
{

public:
    CasselStatus();

    void Init();

    void SetDatabaseName(const std::string &database);

    std::string GetDatabaseName();

    void SetTableName(const std::string &table);

    std::string GetTableName();

    void SetStatus(CasselManagerStatus status);

    CasselManagerStatus GetStatus();

    const std::string GetStatusStr() const;

private:
    CasselManagerStatus status_;
    std::string database_;
    std::string table_;
};

}; // namespace status
}; // namespace manager;
}; // namespace os;
}; // namespace cassel;

#endif