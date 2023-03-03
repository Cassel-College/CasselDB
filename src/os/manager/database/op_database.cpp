#include "op_database.h"

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
namespace database {

using cassel::os::manager::database::OperationDatabase;

OperationDatabase::OperationDatabase() {
    Init();
}

void OperationDatabase::Init() {

}

void OperationDatabase::Do(std::shared_ptr<std::vector<std::string>> operations) {
    std::cout << "-----------------------------------" << std::endl;
    for (auto item : *operations) {
        std::cout << "database:" << item << std::endl;
    }
    std::cout << "-----------------------------------" << std::endl;
};

bool OperationDatabase::Create() {

};

bool OperationDatabase::Select() {

};

bool OperationDatabase::Delete() {

};

bool OperationDatabase::Copy() {

};

bool OperationDatabase::Open() {

};

bool OperationDatabase::Quit() {

};

}; //namespace database
}; //namespace cassel
}; //namespace os
}; //namespace manager

