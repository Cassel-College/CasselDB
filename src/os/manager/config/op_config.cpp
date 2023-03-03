#include "op_config.h"

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
namespace config {

using cassel::os::manager::config::OperationConfig;

OperationConfig::OperationConfig() {
    Init();
}

void OperationConfig::Init() {

}

void OperationConfig::Do(std::shared_ptr<std::vector<std::string>> operations) {
    std::cout << "-----------------------------------" << std::endl;
    for (auto item : *operations) {
        std::cout << "config:" << item << std::endl;
    }
    std::cout << "-----------------------------------" << std::endl;
};

bool OperationConfig::Create() {

};

bool OperationConfig::Select() {

};

bool OperationConfig::Delete() {

};

bool OperationConfig::Copy() {

};

bool OperationConfig::Open() {

};

bool OperationConfig::Quit() {

};

}; //namespace config
}; //namespace cassel
}; //namespace os
}; //namespace manager

