#ifndef CASSEL_OS_MANAGER_TABLE_OP_TABLE_H
#define CASSEL_OS_MANAGER_TABLE_OP_TABLE_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "os/manager/base_operation/base_operation.h"

namespace cassel {
namespace os {
namespace manager {
namespace table {

using cassel::os::manager::base_operation::BaseOperation;

class OperationTable : public BaseOperation {

    public:
    
        OperationTable();

        void Init();

        void Do(std::shared_ptr<std::vector<std::string>>);

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