#include "cassel_manager.h"

namespace cassel {
namespace os {
namespace manager {

using cassel::os::manager::base_operation::BaseOperation;
using cassel::os::manager::def::OperationDefault;
using cassel::os::manager::config::OperationConfig;
using cassel::os::manager::database::OperationDatabase;
using cassel::os::manager::table::OperationTable;

CasselManager::CasselManager() {
    std::cout << "create CasselManager." << std::endl;
    Init();
}

void CasselManager::Init() {
    level = CasselManagerItem::DEFAULT;
}

void CasselManager::ParseOperation(std::shared_ptr<std::vector<std::string>> operations) {

    std::cout << "This is operations: " << std::endl;
    std::shared_ptr<BaseOperation> op_obj = nullptr;
    if (level == CasselManagerItem::DEFAULT) {
        std::cout << "now in DEFAULT model" << std::endl;
        op_obj = std::make_shared<OperationDefault>();
    }
    if (level == CasselManagerItem::DATABASE) {
        std::cout << "now in DATABASE model" << std::endl;
        op_obj = std::make_shared<OperationDatabase>();
    }
    if (level == CasselManagerItem::TABLE) {
        std::cout << "now in TABLE model" << std::endl;
        op_obj = std::make_shared<OperationTable>();
    }
    if (level == CasselManagerItem::CONFIG) {
        std::cout << "now in CONFIG model" << std::endl;
        op_obj = std::make_shared<OperationConfig>();
    }
    op_obj->Do(operations);
    // std::shared_ptr<BaseOperation>
}

};
};
};