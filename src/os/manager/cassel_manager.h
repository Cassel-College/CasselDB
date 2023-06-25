#ifndef CASSEL_OS_MANAGER_CASSEL_MANAGER_H
#define CASSEL_OS_MANAGER_CASSEL_MANAGER_H
/**
 * @brief 
 * 
 * @version 0.1
 * @author liupeng (liupeng.0@outlook.com)
 * @date 2023-03-01
 * @copyright Copyright (c) 2023
 */

#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "os/manager/status/cassel_status.h"
#include "os/manager/base_operation/base_operation.h"
#include "os/manager/config/op_config.h"
#include "os/manager/default/op_default.h"
#include "os/manager/database/op_database.h"
#include "os/manager/table/op_table.h"
#include "os/ui/simple_ui/simple_ui.h"

namespace cassel {
namespace os {
namespace manager {

using cassel::os::manager::base_operation::BaseOperation;
using cassel::os::manager::status::CasselStatus;
using cassel::os::manager::status::CasselManagerStatus;
using cassel::os::manager::status::CasselStatus;
using cassel::os::manager::status::CasselManagerStatus;
using cassel::os::manager::def::OperationDefault;
using cassel::os::manager::config::OperationConfig;
using cassel::os::manager::database::OperationDatabase;
using cassel::os::manager::table::OperationTable;
using cassel::os::ui::SimpleUI;

class CasselManager
{

public:
    CasselManager();

    void Init();

    void ParseOperation(std::shared_ptr<std::vector<std::string>> operations);

    void SendCommandToDefault(std::shared_ptr<std::vector<std::string>> operations);

    void SendCommandToDatabase(std::shared_ptr<std::vector<std::string>> operations);

    void SendCommandToTable(std::shared_ptr<std::vector<std::string>> operations);

    void SendCommandToConfig(std::shared_ptr<std::vector<std::string>> operations);

    const std::string GetCasselStatusStr() const;

    const CasselManagerStatus GetLevelStatus();

private:

    std::shared_ptr<CasselStatus> level_;

};

}; // namespace manager;
}; // namespace os;
}; // namespace cassel;

#endif