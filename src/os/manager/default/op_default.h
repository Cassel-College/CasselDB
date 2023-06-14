#ifndef CASSEL_OS_MANAGER_DEFAULT_OP_DEFAULT_H
#define CASSEL_OS_MANAGER_DEFAULT_OP_DEFAULT_H

#ifndef __FILENAME__
#define __FILENAME__ (strrchr("/" __FILE__, '/') + 1)
#endif

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <set>
#include <map> 

#include "log4cpp/log/log.h"
#include "log4cpp/level/level.h"
#include "log4cpp/log_module/log_module.h"
#include "os/manager/base_operation/base_operation.h"
#include "os/manager/status/cassel_status.h"

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
using namespace cassel::os::manager::status;

class OperationDefault : public BaseOperation {

    public:
    
        OperationDefault();

        void Init();

        std::shared_ptr<CasselStatus> Do(std::shared_ptr<std::vector<std::string>> operations,
                                         std::shared_ptr<CasselStatus> status);

        void InitOperation();

        std::string OperationToParameter(std::shared_ptr<std::vector<std::string>> operations,
                                         std::shared_ptr<CasselStatus> status);

    private:

        bool Create(std::shared_ptr<std::vector<std::string>> operations, std::shared_ptr<CasselStatus> status);
        bool Select(std::shared_ptr<std::vector<std::string>> operations, std::shared_ptr<CasselStatus> status);
        bool Delete(std::shared_ptr<std::vector<std::string>> operations, std::shared_ptr<CasselStatus> status);
        bool Config(std::shared_ptr<std::vector<std::string>> operations, std::shared_ptr<CasselStatus> status);
        bool Copy(std::shared_ptr<std::vector<std::string>> operations, std::shared_ptr<CasselStatus> status);
        bool Open(std::shared_ptr<std::vector<std::string>> operations, std::shared_ptr<CasselStatus> status);
        bool Other(std::shared_ptr<std::vector<std::string>> operations, std::shared_ptr<CasselStatus> status);
        bool Quit(std::shared_ptr<std::vector<std::string>> operations, std::shared_ptr<CasselStatus> status);

        std::set<std::string> operation_names;

        std::map<std::string, int> operation_map;

};

}; //namespace def
}; //namespace cassel
}; //namespace os
}; //namespace manager

#endif