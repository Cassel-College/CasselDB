#ifndef CASSEL_OS_MANAGER_DATABASE_OP_DATABASE_H
#define CASSEL_OS_MANAGER_DATABASE_OP_DATABASE_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "os/manager/base_operation/base_operation.h"

namespace cassel {
namespace os {
namespace manager {
namespace database {

using cassel::os::manager::base_operation::BaseOperation;

class OperationDatabase : public BaseOperation {

    public:
    
        OperationDatabase();

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

}; //namespace database
}; //namespace cassel
}; //namespace os
}; //namespace manager

#endif