#include "cassel_manager.h"

namespace cassel {
namespace os {
namespace manager {

CasselManager::CasselManager() {
    std::cout << "create CasselManager." << std::endl;
    Init();
}

void CasselManager::Init() {
    this->level_ = std::make_shared<CasselStatus>();
    this->level_->SetStatus(CasselManagerStatus::DEFAULT);
}

const std::string CasselManager::GetCasselStatusStr() const {
    return this->level_->GetStatusStr();
}

void CasselManager::ParseOperation(std::shared_ptr<std::vector<std::string>> operations) {

    // std::cout << "This is operations: ";
    // for (std::string operation : *operations) {
    //     std::cout << operation << " ";
    // }
    // std::cout << std::endl;

    bool effect = false;

    switch (level_->GetStatus()) {
        case CasselManagerStatus::DEFAULT:              //  default operation
            this->SendCommandToDefault(operations);
            break;   
        case CasselManagerStatus::DATABASE:             //  database operation
            this->SendCommandToDatabase(operations);
            break;
        case CasselManagerStatus::TABLE:                //  table operation
            this->SendCommandToTable(operations);
            break;   
        case CasselManagerStatus::CONFIG:               //  config operation
            this->SendCommandToConfig(operations);
            break;   
    }
    return;
}

const CasselManagerStatus CasselManager::GetLevelStatus() {
    return this->level_->GetStatus();
}

void CasselManager::SendCommandToDefault(std::shared_ptr<std::vector<std::string>> operations) {
    std::shared_ptr<BaseOperation> op_obj = nullptr;
    std::cout << "now in DEFAULT model" << std::endl;
    op_obj = std::make_shared<OperationDefault>();
    op_obj->Do(operations, this->level_);
}

void CasselManager::SendCommandToDatabase(std::shared_ptr<std::vector<std::string>> operations) {
    std::shared_ptr<BaseOperation> op_obj = nullptr;
    std::cout << "now in DATABASE model" << std::endl;
    op_obj = std::make_shared<OperationDatabase>();
    op_obj->Do(operations, this->level_);
}

void CasselManager::SendCommandToTable(std::shared_ptr<std::vector<std::string>> operations) {
    std::shared_ptr<BaseOperation> op_obj = nullptr;
    std::cout << "now in TABLE model" << std::endl;
    op_obj = std::make_shared<OperationTable>();
    op_obj->Do(operations, this->level_);
}

void CasselManager::SendCommandToConfig(std::shared_ptr<std::vector<std::string>> operations) {
    std::shared_ptr<BaseOperation> op_obj = nullptr;
    std::cout << "now in CONFIG model" << std::endl;
    op_obj = std::make_shared<OperationConfig>();
    op_obj->Do(operations, this->level_);
}

};
};
};