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
using namespace cassel::os::manager::status;

namespace cassel {
namespace os {
namespace manager {
namespace database {

using cassel::os::manager::base_operation::BaseOperation;
using namespace cassel::os::manager::status;

class OperationDatabase : public BaseOperation {

    public:
    
        OperationDatabase();

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

}; //namespace database
}; //namespace cassel
}; //namespace os
}; //namespace manager

#endif