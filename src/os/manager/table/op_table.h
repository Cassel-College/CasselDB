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

using VecStrPtr = std::shared_ptr<std::vector<std::string>>;
using CasselStatusPtr = std::shared_ptr<CasselStatus>;

class OperationTable : public BaseOperation {

    public:
    
        OperationTable();

        void Init();

        void InitOperation();

        std::shared_ptr<CasselStatus> Do(VecStrPtr operations, CasselStatusPtr status);

        std::string OperationToParameter(VecStrPtr operations, CasselStatusPtr status);

    private:

        bool Create(VecStrPtr operations, CasselStatusPtr status);
        bool Select(VecStrPtr operations, CasselStatusPtr status);
        bool Delete(VecStrPtr operations, CasselStatusPtr status);
        bool Config(VecStrPtr operations, CasselStatusPtr status);
        bool Copy(VecStrPtr operations,   CasselStatusPtr status);
        bool Open(VecStrPtr operations,   CasselStatusPtr status);
        bool Other(VecStrPtr operations,  CasselStatusPtr status);
        bool Quit(VecStrPtr operations,   CasselStatusPtr status);

        std::map<std::string, int> operation_map;

};

}; //namespace table
}; //namespace cassel
}; //namespace os
}; //namespace manager

#endif