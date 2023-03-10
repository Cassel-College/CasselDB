#include "base_operation.h"

namespace cassel {
namespace os {
namespace manager {
namespace base_operation {

// BaseOperation::BaseOperation() {}

// void BaseOperation::Do(std::shared_ptr<std::vector<std::string>>) {}

std::string BaseOperation::OperationBuff(std::shared_ptr<std::vector<std::string>> operations) {
    std::string info = "";
    for (auto item : *operations) {
        if (info == "") {
            info = item;
        } else {
            info = info + " " + item;
        }
    }
    return info;
}

}; //namespace base_operation
}; //namespace cassel
}; //namespace os
}; //namespace manager