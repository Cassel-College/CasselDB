#include "op_table.h"

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
namespace table {

using cassel::os::manager::table::OperationTable;

OperationTable::OperationTable() {
    Init();
}

void OperationTable::Init() {

}

void OperationTable::Do(std::shared_ptr<std::vector<std::string>> operations) {
    std::cout << "-----------------------------------" << std::endl;
    for (auto item : *operations) {
        std::cout << operations << std::endl;
    }
    std::cout << "-----------------------------------" << std::endl;
};

bool OperationTable::Create() {

};

bool OperationTable::Select() {

};

bool OperationTable::Delete() {

};

bool OperationTable::Copy() {

};

bool OperationTable::Open() {

};

bool OperationTable::Quit() {

};

}; //namespace table
}; //namespace cassel
}; //namespace os
}; //namespace manager

