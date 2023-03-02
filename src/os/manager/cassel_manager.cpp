#include "cassel_manager.h"

namespace cassel {
namespace os {
namespace manager {

using cassel::os::manager::def::OperationDefault;
using cassel::os::manager::base_operation::BaseOperation;

CasselManager::CasselManager() {
    std::cout << "create CasselManager." << std::endl;
    Init();
}

void CasselManager::Init() {
    level = CasselManagerItem::DEFAULT;
}

void CasselManager::ParseOperation(std::shared_ptr<std::vector<std::string>> operations) {

    for (auto item : *operations) {
        std::cout << item << std::endl;
    }
    std::cout << "This is operations" << std::endl;
    std::shared_ptr<BaseOperation> op_obj = nullptr;
    if (level == CasselManagerItem::DEFAULT) {
        std::cout << "now in DEFAULT model" << std::endl;
        op_obj = std::make_shared<OperationDefault>();
    }
    op_obj->Do(operations);
}


void CasselManager::ShuntModel(std::shared_ptr<std::vector<std::string>> operations) {

    if (level == CasselManagerItem::DEFAULT) {
        std::cout << "now in DEFAULT model" << std::endl;
        std::shared_ptr<OperationDefault> op_obj = std::make_shared<OperationDefault>();

    }
    if (level == CasselManagerItem::DATABASE) {
        std::cout << "now in DATABASE model" << std::endl;
    }
    if (level == CasselManagerItem::TABLE) {
        std::cout << "now in TABLE model" << std::endl;
    }
    if (level == CasselManagerItem::CONFIG) {
        std::cout << "now in CONFIG model" << std::endl;
    }
}


void CasselManager::ShuntOperation(std::shared_ptr<std::vector<std::string>> operations) {
    std::cout << "now in CONFIG model" << std::endl;
}


};
};
};