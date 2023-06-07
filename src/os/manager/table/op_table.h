#ifndef CASSEL_OS_MANAGER_TABLE_OP_TABLE_H
#define CASSEL_OS_MANAGER_TABLE_OP_TABLE_H

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
#include "os/manager/status/cassel_status.h"

namespace cassel {
namespace os {
namespace manager {
namespace table {

using cassel::os::manager::base_operation::BaseOperation;
using namespace cassel::os::manager::status;

class OperationTable : public BaseOperation {

    public:
    
        OperationTable();

        void Init();

        CasselStatus Do(std::shared_ptr<std::vector<std::string>> operations, CasselStatus status);

    private:

        bool Create();
        bool Select();
        bool Delete();
        bool Copy();
        bool Open();
        bool Quit();

};

}; //namespace table
}; //namespace cassel
}; //namespace os
}; //namespace manager

#endif