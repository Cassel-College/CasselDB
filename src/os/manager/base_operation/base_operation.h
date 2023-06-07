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

using namespace cassel::os::manager::status::CasselStatus;

class BaseOperation {

    public:
        virtual CasselStatus Do(std::shared_ptr<std::vector<std::string>> operations, CasselStatus status)=0;

        std::string OperationStrBuff(std::shared_ptr<std::vector<std::string>> operations);
};

}; //namespace base_operation
}; //namespace cassel
}; //namespace os
}; //namespace manager

#endif