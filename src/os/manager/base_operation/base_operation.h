#ifndef CASSEL_OS_MANAGER_BASE_OPERATION_BASE_OPERATION_H
#define CASSEL_OS_MANAGER_BASE_OPERATION_BASE_OPERATION_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "os/manager/status/cassel_status.h"

namespace cassel {
namespace os {
namespace manager {
namespace base_operation {

using namespace cassel::os::manager::status;

using VecStrPtr = std::shared_ptr<std::vector<std::string>>;
using CasselStatusPtr = std::shared_ptr<CasselStatus>;

class BaseOperation {

    public:
        virtual std::shared_ptr<CasselStatus> Do(VecStrPtr operations, CasselStatusPtr status)=0;

        std::string OperationStrBuff(std::shared_ptr<std::vector<std::string>> operations);
};

}; //namespace base_operation
}; //namespace cassel
}; //namespace os
}; //namespace manager

#endif