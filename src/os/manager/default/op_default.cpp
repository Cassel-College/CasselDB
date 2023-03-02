#include "op_default.h"

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

using cassel::os::manager::def::OperationDefault;

OperationDefault::OperationDefault() {
    Init();
}

void OperationDefault::Init() {

}

void OperationDefault::Do(std::shared_ptr<std::vector<std::string>> operations) {
    std::cout << "-----------------------------------" << std::endl;
    for (auto item : *operations) {
        std::cout << operations << std::endl;
    }
    std::cout << "-----------------------------------" << std::endl;
};

bool OperationDefault::Create() {

};

bool OperationDefault::Select() {

};

bool OperationDefault::Delete() {

};

bool OperationDefault::Copy() {

};

bool OperationDefault::Open() {

};

bool OperationDefault::Quit() {

};

}; //namespace def
}; //namespace cassel
}; //namespace os
}; //namespace manager

