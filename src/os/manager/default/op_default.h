#ifndef CASSEL_OS_MANAGER_DEFAULT_OP_DEFAULT_H
#define CASSEL_OS_MANAGER_DEFAULT_OP_DEFAULT_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "os/manager/base_operation/base_operation.h"

/**
 * @brief 
 * 
 * @version 0.1
 * @author liupeng (liupeng.0@outlook.com)
 * @date 2023-03-02
 * @copyright Copyright (c) 2023
 */

namespace cassel {
namespace os {
namespace manager {
namespace def {

using cassel::os::manager::base_operation::BaseOperation;

class OperationDefault : public BaseOperation {

    public:
    
        OperationDefault();

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

}; //namespace def
}; //namespace cassel
}; //namespace os
}; //namespace manager

#endif