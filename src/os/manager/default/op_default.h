#ifndef CASSEL_OS_MANAGER_DEFAULT_OP_DEFAULT_H
#define CASSEL_OS_MANAGER_DEFAULT_OP_DEFAULT_H

#ifndef __FILENAME__
#define __FILENAME__ (strrchr("/" __FILE__, '/') + 1)
#endif

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <set>
#include <map> 

#include "log4cpp/log/log.h"
#include "log4cpp/level/level.h"
#include "log4cpp/log_module/log_module.h"
#include "os/manager/base_operation/base_operation.h"
#include "os/manager/status/cassel_status.h"
#include "module/create/createDB/create_database.h"
#include "config/cassel_config/cassel_config.h"
#include "module/select/database/select_database.h"
#include "os/ui/simple_ui/simple_ui.h"

/**
 * @brief 
 * 
 * @version 0.1
 * @author liupeng (liupeng.0@outlook.com)
 * @date 2023-03-02
 * @copyright Copyright (c) 2023
 */

namespace cassel {
namespace os {
namespace manager {
namespace def {

using namespace cassel::os::manager::status;

using db_config::cassel_config::CasselConfig;
using module::create::CreateDatabase;
using module::select::select_databases::SelectDataBase;
using cassel::os::manager::base_operation::BaseOperation;
using cassel::os::ui::SimpleUI;

using VecStrPtr = std::shared_ptr<std::vector<std::string>>;
using CasselStatusPtr = std::shared_ptr<CasselStatus>;

class OperationDefault : public BaseOperation {

    public:
    
        OperationDefault();

        void Init();

        void InitOperation();

        std::shared_ptr<CasselStatus> Do(VecStrPtr operations, CasselStatusPtr status);

        std::string OperationToParameter(VecStrPtr operations, CasselStatusPtr status);

    private:

        bool Create(VecStrPtr operations, CasselStatusPtr status);
        bool Select(VecStrPtr operations, CasselStatusPtr status);
        bool Delete(VecStrPtr operations, CasselStatusPtr status);
        bool Config(VecStrPtr operations, CasselStatusPtr status);
        bool Status(VecStrPtr operations, CasselStatusPtr status);
        bool Copy(VecStrPtr operations,   CasselStatusPtr status);
        bool Open(VecStrPtr operations,   CasselStatusPtr status);
        bool Other(VecStrPtr operations,  CasselStatusPtr status);
        bool Quit(VecStrPtr operations,   CasselStatusPtr status);

        std::map<std::string, int> operation_map;

};

}; //namespace def
}; //namespace cassel
}; //namespace os
}; //namespace manager

#endif