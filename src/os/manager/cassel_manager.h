#ifndef CASSEL_OS_MANAGER_CASSEL_MANAGER_H
#define CASSEL_OS_MANAGER_CASSEL_MANAGER_H
/**
 * @brief 
 * 
 * @version 0.1
 * @author liupeng (liupeng.0@outlook.com)
 * @date 2023-03-01
 * @copyright Copyright (c) 2023
 */

#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "os/manager/default/op_default.h"
#include "os/manager/base_operation/base_operation.h"

namespace cassel {
namespace os {
namespace manager {

enum class CasselManagerItem {
    DEFAULT,
    DATABASE,
    TABLE,
    CONFIG
};

class CasselManager
{

public:
    CasselManager();

    void Init();

    void ParseOperation(std::shared_ptr<std::vector<std::string>> operations);

    void ShuntModel(std::shared_ptr<std::vector<std::string>> operations);

    void ShuntOperation(std::shared_ptr<std::vector<std::string>> operations);

private:

    CasselManagerItem level;

};


}; // namespace manager;
}; // namespace os;
}; // namespace cassel;

#endif