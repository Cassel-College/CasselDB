#ifndef CASSEL_OS_MANAGER_DATABASE_OP_DATABASE_H
#define CASSEL_OS_MANAGER_DATABASE_OP_DATABASE_H

#ifndef __FILENAME__
#define __FILENAME__ (strrchr("/" __FILE__, '/') + 1)
#endif

#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "log4cpp/log/log.h"
#include "log4cpp/level/level.h"
#include "log4cpp/log_module/log_module.h"
#include "os/manager/base_operation/base_operation.h"
#include "os/ui/simple_ui/simple_ui.h"
#include "module/create/createTB/create_table.h"
#include "module/select/table/select_table.h"
#include "config/cassel_config/cassel_config.h"

namespace cassel {
namespace os {
namespace manager {
namespace database {

using namespace cassel::os::manager::status;

using db_config::cassel_config::CasselConfig;
using cassel::os::manager::base_operation::BaseOperation;
using cassel::os::ui::SimpleUI;
using module::create::CreateTable;
using module::select::select_table::SelectTable;

using VecStrPtr = std::shared_ptr<std::vector<std::string>>;
using CasselStatusPtr = std::shared_ptr<CasselStatus>;
using SelectTablePrt = std::shared_ptr<SelectTable>;

class OperationDatabase : public BaseOperation {

    public:
    
        OperationDatabase();

        void Init();

        void InitOperation();

        std::shared_ptr<CasselStatus> Do(VecStrPtr operations, CasselStatusPtr status);

        std::string OperationToParameter(VecStrPtr operations, CasselStatusPtr status);
        
    private:
        bool Create(VecStrPtr operations, CasselStatusPtr status);
        bool Select(VecStrPtr operations, CasselStatusPtr status);
        bool Delete(VecStrPtr operations, CasselStatusPtr status);
        bool Status(VecStrPtr operations, CasselStatusPtr status);
        bool Copy(VecStrPtr operations,   CasselStatusPtr status);
        bool Open(VecStrPtr operations,   CasselStatusPtr status);
        bool Quit(VecStrPtr operations,   CasselStatusPtr status);

        std::map<std::string, int> operation_map;
};

}; //namespace database
}; //namespace cassel
}; //namespace os
}; //namespace manager

#endif