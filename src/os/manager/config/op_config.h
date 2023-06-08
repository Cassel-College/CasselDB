#ifndef CASSEL_OS_MANAGER_CONFIG_OP_CONFIG_H
#define CASSEL_OS_MANAGER_CONFIG_OP_CONFIG_H

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
namespace config {

using cassel::os::manager::base_operation::BaseOperation;
using namespace cassel::os::manager::status;

class OperationConfig : public BaseOperation {

    public:
    
        OperationConfig();

        void Init();

        std::shared_ptr<CasselStatus> Do(std::shared_ptr<std::vector<std::string>> operations,
                                         std::shared_ptr<CasselStatus> status);

    private:

        bool Create();
        bool Select();
        bool Delete();
        bool Copy();
        bool Open();
        bool Quit();
};

}; //namespace config
}; //namespace cassel
}; //namespace os
}; //namespace manager

#endif