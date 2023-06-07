#include "cassel_manager.h"

namespace cassel {
namespace os {
namespace manager {

CasselManager::CasselManager() {
    std::cout << "create CasselManager." << std::endl;
    Init();
}

void CasselManager::Init() {
    level = CasselStatus();
    level.SetStatus(CasselManagerStatus::DEFAULT);
}

void CasselManager::ParseOperation(std::shared_ptr<std::vector<std::string>> operations) {

    std::cout << "This is operations: ";
    for (std::string operation : *operations) {
        std::cout << operation << " ";
    }
    std::cout << std::endl;

    std::shared_ptr<BaseOperation> op_obj = nullptr;
    bool effect = false;
    if ((!effect) && (level.GetStatus() == CasselManagerStatus::DEFAULT)) {
        std::cout << "now in DEFAULT model" << std::endl;
        op_obj = std::make_shared<OperationDefault>();
        op_obj->Do(operations, level);
        effect = true;
    }
    
    if ((!effect) && (level.GetStatus() == CasselManagerStatus::DATABASE)) {
        std::cout << "now in DATABASE model" << std::endl;
        op_obj = std::make_shared<OperationDatabase>();
        op_obj->Do(operations, level);
        effect = true;
    }

    if ((!effect) && (level.GetStatus() == CasselManagerStatus::TABLE)) {
        std::cout << "now in TABLE model" << std::endl;
        op_obj = std::make_shared<OperationTable>();
        op_obj->Do(operations, level);
        effect = true;
    }

    if ((!effect) && (level.GetStatus() == CasselManagerStatus::CONFIG)) {
        std::cout << "now in CONFIG model" << std::endl;
        op_obj = std::make_shared<OperationConfig>();
        op_obj->Do(operations, level);
        effect = true;
    }
   
    // std::shared_ptr<BaseOperation>
    return;
}

};
};
};