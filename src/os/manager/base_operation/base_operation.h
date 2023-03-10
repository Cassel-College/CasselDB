#ifndef CASSEL_OS_MANAGER_BASE_OPERATION_BASE_OPERATION_H
#define CASSEL_OS_MANAGER_BASE_OPERATION_BASE_OPERATION_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>

namespace cassel {
namespace os {
namespace manager {
namespace base_operation {

class BaseOperation {

    public:
        virtual void Do(std::shared_ptr<std::vector<std::string>> operations)=0;

        std::string OperationStrBuff(std::shared_ptr<std::vector<std::string>> operations);
};

}; //namespace base_operation
}; //namespace cassel
}; //namespace os
}; //namespace manager

#endif